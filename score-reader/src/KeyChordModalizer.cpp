#include "KeyChordModalizer.hpp"
using namespace score::scale;

const std::wstring KeyString(const Modal& key, const bool isMajor)
{
	return Modalize::ToString(key, false) + (isMajor ? L"" : L"m");
}

const ScaleIntervals& KeyInterval(const Modal& key, const bool isMajor)
{
	const ScaleTheory scale = ScaleTheory({0, 2, 4, 5, 7, 9, 11});

	return (isMajor ? scale.GetScale(key) : scale.GetScale(
		(int)key + 9 > 11 ? (int)key - 12 + 9 : (int)key));
}

KeyChordModalizer::KeyChordModalizer(const Modal& key, const ModeTheory& mode)
	: mode(mode), key(key)
{
	
}

const size_t SubstituteKeys(const Modal a, const Modal b)
{
	const size_t retval = (size_t)a - (size_t)b;
	return retval > 11 ? retval - 12 : retval;
}

ModalIndices MergeInterval(const Modal& modal, const ModeScale& scale)
{
	ModalIndices retval(scale.Size());

	for (size_t i = 0; i < scale.Size(); ++i)
	{
		retval[i] = scale.GetInterval(i) + (int)modal;
	}

	return retval;
}

const ModalIndices KeyChordModalizer::GetPrimaryMode(const std::wstring& chordStr) const
{
	const auto root = (Modal)Modalize::ToModal(chordStr);

	const auto& scale = mode.GetMode(root);		// 早めにこちらをテストしたほうがいいような気がする

	return MergeInterval(root, scale);
}
