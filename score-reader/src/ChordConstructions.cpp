#include "ChordConstruction.hpp"

template <typename T>
const int score::chord::ChordConstructions::MatchArray(const T& constructions, const std::wstring& str) const
{
	int i = 0;
	for (const auto& cons : constructions)
	{
		if (std::regex_match(str, cons.Regex()))
		{
			++i; break;
		}
	}
	return i;
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchRoots(const std::wstring& str) const
{
	return roots[MatchArray(roots, str)];
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchTones(const std::wstring& str) const
{
	return tones[MatchArray(tones, str)];
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchFifthes(const std::wstring& str) const
{
	return fifthes[MatchArray(fifthes, str)];
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchDominants(const std::wstring& str) const
{
	return dominants[MatchArray(dominants, str)];
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchTensions(const std::wstring& str) const
{
	return tensions[MatchArray(tensions, str)];
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchOnChord(const std::wstring& str) const
{
	return onchords[MatchArray(onchords, str)];
}