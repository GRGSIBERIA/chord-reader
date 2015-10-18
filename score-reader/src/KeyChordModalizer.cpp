#include "KeyChordModalizer.hpp"
using namespace score::scale;

const ScaleTheory KeyChordModalizer::majtheory = ScaleTheory({ 0, 2, 4, 5, 7, 9, 11 });
const ScaleTheory KeyChordModalizer::harmonic = ScaleTheory({ 0, 2, 3, 5, 7, 8, 11 });
const ScaleTheory KeyChordModalizer::natural = ScaleTheory({ 0, 2, 3, 5, 7, 8, 10 });
const ScaleTheory KeyChordModalizer::melodic = ScaleTheory({ 0, 2, 3, 5, 7, 9, 11 });
const ScaleTheory* KeyChordModalizer::current = &harmonic;

int RoundInterval(int num)
{
	if (num > 11) return RoundInterval(num - 12);
	else if (num < 0) return RoundInterval(num + 12);
	return num;
}

void KeyChordModalizer::CalcModeScalesOnRoot(const size_t root)
{
	for (size_t modeIndex = 0; modeIndex < scale.Size(); ++modeIndex)
	{
		const auto& mode = mtheory.GetMode(modeIndex);

		for (size_t intervalIndex = 0; intervalIndex < scale.Size(); ++intervalIndex)
		{
			int tmp = mode.GetInterval(intervalIndex) + (int)key + scale.GetInterval(root);
			tmp = RoundInterval(tmp);

			modeScale[root][modeIndex][intervalIndex] = tmp;
		}
	}
}

void KeyChordModalizer::CalcAvailableScaleOnRoot(const size_t root)
{
	const auto& primary = modeScale[root][root];
	const auto& availableOnMode = mtheory.GetMode(root).GetAvailableScale();

	for (size_t modeIndex = 0; modeIndex < scale.Size(); ++modeIndex)
	{
		const auto& targetScale = modeScale[root][modeIndex];
		const auto& targetMode = mtheory.GetMode(modeIndex);

		for (size_t intervalIndex = 0; intervalIndex < scale.Size(); ++intervalIndex)
		{
			// Available Note以外は追加しない方針
			usables[root][modeIndex].push_back(targetScale[intervalIndex]);
			if (availableOnMode[intervalIndex] == targetMode.GetInterval(intervalIndex))
			{
				availables[root][modeIndex].push_back(targetScale[intervalIndex]);
			}
		}
	}
}

const ScaleTheory& KeyChordModalizer::GetMinor(const MinorType minor) const
{
	switch (minor)
	{
	case MinorType::Harmonic:
		return harmonic;
	case MinorType::Natural:
		return natural;
	case MinorType::Melodic:
		return melodic;
	}
	throw std::exception("知らん奴が投げられてるぞ");
}

KeyChordModalizer::KeyChordModalizer(const std::wstring& key, const MinorType minor)
	: KeyChordModalizer(key, Modalize::ToModal(key), Modalize::HasMinor(key) ? GetMinor(minor) : majtheory, { 0, 2, 4, 6 }, minor)
{
	// 委譲コンストラクタ
}

KeyChordModalizer::KeyChordModalizer(const std::wstring& key) 
	: KeyChordModalizer(key, Modalize::ToModal(key), Modalize::HasMinor(key) ? *current : majtheory, { 0, 2, 4, 6 })
{
	// 委譲コンストラクタ
}

KeyChordModalizer::KeyChordModalizer(const std::wstring& keyName, const Modal& key, const ScaleTheory& theory, const ScaleIndices& chordTone, const MinorType minor)
	: mtheory(Scale(keyName, theory.GetScale(key)), chordTone), key(key), scale(keyName, theory.GetScale(key)), keyName(keyName), minorType(minor)
{
	modeScale = ModesOnScale(scale.Size(), 
		ModeModalScales(scale.Size(), 
		ModeModals(scale.Size())));
	availables = ModesOnScale(scale.Size(),
		ModeModalScales(scale.Size()));
	usables = ModesOnScale(scale.Size(),
		ModeModalScales(scale.Size()));

	// 音階ごとにモードスケールを展開する

	for (size_t root = 0; root < scale.Size(); ++root)
	{
		// このループで，あるルート音に対応するすべてのモードスケールを求める
		CalcModeScalesOnRoot(root);

		// このループで，モードごとに演奏可能な楽音を追加する
		CalcAvailableScaleOnRoot(root);
	}
}

const ModeModals& KeyChordModalizer::PrimaryModeScale(const std::wstring& str) const
{
	auto index = scale.GetIndex(str);
	return ModeScale(index, index);
}

const ModeModals& KeyChordModalizer::PrimaryAvailableScale(const std::wstring& str) const
{
	auto index = scale.GetIndex(str);
	return AvailableScale(index, index);
}

const ModeModals& KeyChordModalizer::AvailableScale(const std::wstring& str, const size_t mode_num) const
{
	auto index = scale.GetIndex(str);
	return AvailableScale(index, mode_num);
}

const ModeModals& KeyChordModalizer::ModeScale(const std::wstring& str, const size_t mode_num) const
{
	auto index = scale.GetIndex(str);
	return ModeScale(index, mode_num);
}

const ModeModalScales& KeyChordModalizer::Availables(const std::wstring& chord) const
{
	return availables[scale.GetIndex(chord)];
}

/**************************************************************************************************
* ここから先は新仕様のメンバ関数
*/

const ChordScale KeyChordModalizer::Mode(const size_t root, const size_t mode_num) const 
{ 
	return ChordScale(Diatonics[root], root, mode_num, ModeScale(root, mode_num), AvailableScale(root, mode_num), usables[root][mode_num], *this); 
}
const ChordScale KeyChordModalizer::Mode(const std::wstring& chord, const size_t mode_num) const
{
	return Mode(scale.GetIndex(chord), mode_num);
}
const ChordScale KeyChordModalizer::PrimaryMode(const size_t root) const
{
	return ChordScale(Diatonics[root], root, root, PrimaryModeScale(root), PrimaryAvailableScale(root), usables[root][root], *this);
}
const ChordScale KeyChordModalizer::PrimaryMode(const std::wstring& root) const
{
	return PrimaryMode(scale.GetIndex(root));
}