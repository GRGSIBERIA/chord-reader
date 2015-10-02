#include "KeyChordModalizer.hpp"
using namespace score::scale;

const ScaleTheory KeyChordModalizer::stheory = ScaleTheory({ 0, 2, 4, 5, 7, 9, 11 });

void KeyChordModalizer::CalcModeScalesOnRoot(const size_t root)
{
	for (size_t modeIndex = 0; modeIndex < scale.Size(); ++modeIndex)
	{
		const auto& mode = mtheory.GetMode(modeIndex);

		for (size_t intervalIndex = 0; intervalIndex < scale.Size(); ++intervalIndex)
		{
			int tmp = mode.GetInterval(intervalIndex) + (int)key + scale.GetInterval(root);
			tmp = tmp > 11 ? tmp - 12 : tmp;

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

KeyChordModalizer::KeyChordModalizer(const Modal& key)
	: mtheory(Scale(L"", stheory.GetScale(key)), { 0, 2, 4, 6 }), key(key), scale(L"", stheory.GetScale(key)) 
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