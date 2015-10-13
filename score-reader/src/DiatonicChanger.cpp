#include "DiatonicChanger.hpp"
using namespace score::chord;
using namespace score::scale;

const ChordScale DiatonicChanger::SecondaryDominant(const std::wstring& targetChord, const bool useMinor = false)
{
	const auto& secondaryKey = useMinor ? ScaleDatabase::Find(targetChord) : ScaleDatabase::Major(targetChord);
	const auto& chord = secondaryKey.Diatonics[4];
	return secondaryKey.Available(4, 4);
}

const ChordScale DiatonicChanger::ModalInterchange(const std::wstring& key, const std::wstring& chord, const RelatedKey related = RelatedKey::Parallel)
{
	const auto index = ScaleDatabase::Find(key).ModeIndex(chord);

	switch (related)
	{
	case RelatedKey::Parallel:
		return ScaleDatabase::Parallel(key).PrimaryMode(index);

	case RelatedKey::Relative:
		return ScaleDatabase::Relative(key).PrimaryMode(index);

	case RelatedKey::Dominant:
		return ScaleDatabase::Dominant(key).PrimaryMode(index);

	case RelatedKey::Subdominant:
		return ScaleDatabase::Subdominant(key).PrimaryMode(index);

	case RelatedKey::MinorDominant:
		return ScaleDatabase::MinorDominant(key).PrimaryMode(index);

	case RelatedKey::MinorSubdominant:
		return ScaleDatabase::MinorSubdominant(key).PrimaryMode(index);
		break;
	}

	throw UndefinedRelatedKeyException();
}