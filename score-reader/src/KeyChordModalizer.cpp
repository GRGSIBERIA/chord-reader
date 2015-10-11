#include "KeyChordModalizer.hpp"
using namespace score::scale;

const ScaleTheory KeyChordModalizer::majtheory = ScaleTheory({ 0, 2, 4, 5, 7, 9, 11 });
const ScaleTheory KeyChordModalizer::mintheory = ScaleTheory({ 0, 2, 3, 5, 7, 8, 10 });

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
			if (availableOnMode[intervalIndex] != targetMode.GetInterval(intervalIndex))
				continue;

			availables[root][modeIndex].push_back(targetScale[intervalIndex]);
		}
	}
}

KeyChordModalizer::KeyChordModalizer(const std::wstring& key) 
	: KeyChordModalizer(key, Modalize::ToModal(key), Modalize::HasMinor(key) ? mintheory : majtheory, { 0, 2, 4, 6 })
{
	// 委譲コンストラクタ
}

KeyChordModalizer::KeyChordModalizer(const std::wstring& keyName, const Modal& key, const ScaleTheory& theory, const ScaleIndices& chordTone)
	: mtheory(Scale(keyName, theory.GetScale(key)), chordTone), key(key), scale(keyName, theory.GetScale(key)), keyName(keyName)
{
	modeScale = ModesOnScale(scale.Size(), 
		ModeModalScales(scale.Size(), 
		ModeModals(scale.Size())));
	availables = ModesOnScale(scale.Size(),
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

const ModeModals& KeyChordModalizer::GetPrimaryModeScale(const std::wstring& str) const
{
	auto index = scale.GetIndex(str);
	return GetModeScale(index, index);
}

const ModeModals& KeyChordModalizer::GetPrimaryAvailableScale(const std::wstring& str) const
{
	auto index = scale.GetIndex(str);
	return GetAvailableScale(index, index);
}

const ModeModals& KeyChordModalizer::GetAvailableScale(const std::wstring& str, const size_t mode_num) const
{
	auto index = scale.GetIndex(str);
	return GetAvailableScale(index, mode_num);
}

const ModeModals& KeyChordModalizer::GetModeScale(const std::wstring& str, const size_t mode_num) const
{
	auto index = scale.GetIndex(str);
	return GetModeScale(index, mode_num);
}

const ModeModalScales& KeyChordModalizer::GetAvailables(const std::wstring& chord) const
{
	auto index = scale.GetIndex(chord);
	return availables[index];
}