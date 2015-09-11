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

const int score::chord::ChordConstructions::MatchRoots(const std::wstring& str)
{
	return MatchArray(roots, str);
}

const int score::chord::ChordConstructions::MatchTones(const std::wstring& str)
{
	return MatchArray(tones, str);
}
const int score::chord::ChordConstructions::MatchFifthes(const std::wstring& str)
{
	return MatchArray(fifthes, str);
}
const int score::chord::ChordConstructions::MatchDominants(const std::wstring& str)
{
	return MatchArray(dominants, str);
}

const int score::chord::ChordConstructions::MatchTensions(const std::wstring& str)
{
	return MatchArray(tensions, str);
}