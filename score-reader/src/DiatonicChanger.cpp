#include "DiatonicChanger.hpp"
using namespace score::chord;
using namespace score::scale;

const ChordScale DiatonicChanger::SecondaryDominant(const std::wstring& targetChord, const bool useMinor = false)
{
	const auto& secondaryKey = useMinor ? ScaleDatabase::Find(targetChord) : ScaleDatabase::Major(targetChord);
	const auto& chord = secondaryKey.Diatonics[4];
	return secondaryKey.Mode(4, 4);
}

const ChordScale DiatonicChanger::ModalInterchange(const std::wstring& key, const std::wstring& chord, const RelatedKey related = RelatedKey::Parallel)
{
	const auto& base = ScaleDatabase::Find(key);
	
	const auto modeIndex = base.ModeIndex(chord);

	const auto& changed = ScaleDatabase::Related(key, related);

	const auto changedIndex = base.ModeIndex(changed.KeyName);

	int targetIndex = modeIndex < changedIndex ? modeIndex + 7 : modeIndex;
	
	return changed.PrimaryMode(targetIndex - changedIndex);
}