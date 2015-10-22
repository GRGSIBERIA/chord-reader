#include "ChordUnit.hpp"
using namespace score::score;
using namespace score::scale;

ChordUnit::ChordUnit(const std::wstring& part, const std::wstring& key, const std::wstring& chordName, const int count)
	: key(key), chordPtr(chord::ChordFactory::CreateChord(chordName)), count(count), part(part), modalizer(scale::ScaleDatabase::Find(key))
{
	scaleIndex = modalizer.ModeIndex(chordName);
}

const ModeModals ChordUnit::Scale(const size_t modeIndex) const 
{ 
	return modalizer.Mode(scaleIndex, modeIndex).Scale(modeIndex); 
}
const ModeModals ChordUnit::Scale() const
{
	return modalizer.Mode(scaleIndex, scaleIndex).Scale(scaleIndex);
}
const ModeModals ChordUnit::Available(const size_t modeIndex) const
{
	return modalizer.Mode(scaleIndex, modeIndex).Available(modeIndex);
}
const ModeModals ChordUnit::Available() const
{
	return modalizer.Mode(scaleIndex, scaleIndex).Available(scaleIndex);
}
const ModeModals ChordUnit::Usable(const size_t modeIndex) const
{
	return modalizer.Mode(scaleIndex, modeIndex).Usable(modeIndex);
}
const ModeModals ChordUnit::Usable() const
{
	return modalizer.Mode(scaleIndex, scaleIndex).Usable(scaleIndex);
}


ChordUnitArray::Itr ChordUnitArray::NextPart(ChordUnitArray::Itr& now) const
{
	return std::find_if(now, end(), [now](const ChordUnit& b) { return now->Part != b.Part; });
}
ChordUnitArray::Itr ChordUnitArray::NextKey(ChordUnitArray::Itr& now) const
{
	return std::find_if(now, end(), [now](const ChordUnit& b) { return now->Key != b.Key; });
}