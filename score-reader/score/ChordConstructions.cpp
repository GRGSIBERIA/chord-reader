#include "ChordConstruction.hpp"

template <typename T>
const int score::chord::ChordConstructions::MatchArray(const T& constructions, const std::wstring& str)
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

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchRoots(const std::wstring& str)
{
	return roots[MatchArray(roots, str)];
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchTones(const std::wstring& str)
{
	return tones[MatchArray(tones, str)];
}
const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchFifthes(const std::wstring& str)
{
	return fifthes[MatchArray(fifthes, str)];
}
const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchDominants(const std::wstring& str)
{
	return dominants[MatchArray(dominants, str)];
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchTensions(const std::wstring& str)
{
	return tensions[MatchArray(tensions, str)];
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchOnChord(const std::wstring& str)
{
	return onchords[MatchArray(onchords, str)];
}