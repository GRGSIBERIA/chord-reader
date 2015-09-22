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
	: mode(Scale(KeyString(key, isMajor), KeyInterval(key, isMajor)), { 0, 2, 4, 6 })
{
	for (size_t si = 0; si < 7; ++si)
	{
		const auto& modescale = mode.GetMode(si);
		for (size_t mi = 0; mi < 7; ++mi)
		{
			const auto interval = modescale.GetInterval(mi);
			scales[si][mi] = interval + (int)key;
			if (scales[si][mi] > 11) scales[si][mi] -= 12;
		}
	}
}