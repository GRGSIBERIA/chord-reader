#include "KeyChordModalizer.hpp"
using namespace score::scale;

const std::wstring KeyString(const Modal& key, const bool isMajor)
{
	return Modalize::ToString(key, false) + (isMajor ? L"" : L"m");
}

const ScaleIntervals& KeyInterval(const Modal& key, const bool isMajor)
{
	static const ScaleTheory scale;

	return (isMajor ? scale.GetScale(key) : scale.GetScale(
		(int)key + 9 > 11 ? (int)key - 12 + 9 : (int)key));
}

KeyChordModalizer::KeyChordModalizer(const Modal& key, const bool isMajor)
	: mode(Scale(KeyString(key, isMajor), KeyInterval(key, isMajor)), { 0, 2, 4, 6 }), key(key)
{
	
}

const size_t SubKeys(const Modal a, const Modal b)
{
	const size_t retval = (size_t)a - (size_t)b;
	return retval > 11 ? retval - 12 : retval;
}

const ModeScale& KeyChordModalizer::GetPrimaryMode(const std::wstring& chordStr) const
{
	const auto root = SubKeys(Modalize::ToModal(chordStr), key);

	return mode.GetMode(root);		// 早めにこちらをテストしたほうがいいような気がする
}
