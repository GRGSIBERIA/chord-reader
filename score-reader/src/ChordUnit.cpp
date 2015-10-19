#include "ChordUnit.hpp"
using namespace score::score;
using namespace score::scale;

ChordUnit::ChordUnit(const std::wstring& part, const std::wstring& key, const std::wstring& chordName, const int count)
	: key(key), chordPtr(chord::ChordFactory::CreateChord(chordName)), count(count), part(part), modalizer(scale::ScaleDatabase::Find(key))
{
	scaleIndex = modalizer.ModeIndex(chordName);
}

const ChordScale ChordUnit::Scale(const size_t modeIndex) const 
{ 
	return modalizer.Mode(scaleIndex, modeIndex); 
}
const ChordScale ChordUnit::Scale() const
{
	return modalizer.Mode(scaleIndex, scaleIndex);
}