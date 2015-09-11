#include "ChordConstruction.hpp"

template <typename T>
const int score::chord::ChordRegex::MatchArray(const T& regices, const std::wstring& str)
{
	int i = 0;
	for (const auto& re : regices)
	{
		if (std::regex_match(str, re))
		{
			++i; break;
		}
	}
	return i;
}

const int score::chord::ChordRegex::MatchRoots(const std::wstring& str)
{
	return MatchArray(roots, str);
}

const int score::chord::ChordRegex::MatchTones(const std::wstring& str)
{
	return MatchArray(tones, str);
}
const int score::chord::ChordRegex::MatchFifthes(const std::wstring& str)
{
	return MatchArray(fifthes, str);
}
const int score::chord::ChordRegex::MatchDominants(const std::wstring& str)
{
	return MatchArray(dominants, str);
}

const int score::chord::ChordRegex::MatchTensions(const std::wstring& str)
{
	return MatchArray(tensions, str);
}