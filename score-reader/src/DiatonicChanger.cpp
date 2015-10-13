#include "DiatonicChanger.hpp"
using namespace score::chord;
using namespace score::scale;

const ChordScale DiatonicChanger::SecondaryDominant(const std::wstring& targetChord)
{
	const auto& secondaryKey = ScaleDatabase::Major(targetChord);
	const auto& chord = secondaryKey.Diatonics[4];
	return secondaryKey.Available(4, 4);
}