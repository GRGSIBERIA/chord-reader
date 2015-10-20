#include "ChordScale.hpp"
#include "KeyChordModalizer.hpp"
using namespace score::scale;

const ModeModals& ChordScale::Scale(const size_t i) const
{
	return modalizer.ModeScale(scaleIndex, i);
}
const ModeModals& ChordScale::Available(const size_t i) const
{
	return modalizer.AvailableScale(scaleIndex, i);
}
const ModeModals& ChordScale::Usable(const size_t i) const
{
	return modalizer.UsableScale(scaleIndex, i);
}
const ModeModals& ChordScale::Scale() const
{
	return modalizer.ModeScale(scaleIndex, scaleIndex);
}
const ModeModals& ChordScale::Available() const
{
	return modalizer.AvailableScale(scaleIndex, scaleIndex);
}
const ModeModals& ChordScale::Usable() const
{
	return modalizer.UsableScale(scaleIndex, scaleIndex);
}