#include "ChordConstruction.hpp"

template <typename T>
const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchArray(const T& constructions, const std::wstring& str) const
{
	size_t i = 0;
	for (const auto& cons : constructions)
	{
		if (std::regex_match(str, cons.Regex()))
			break;
		++i;
	}
	if (constructions.size() <= i)
		return idef;
	return constructions[i];
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchRoots(const std::wstring& str) const
{
	return MatchArray(roots, str);
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchTones(const std::wstring& str) const
{
	const auto& tone = MatchArray(tones, str);
	static const score::chord::Major3rd maj;
	if (tone.Name() == L"Idefinite")
		return maj;
	return tone;
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchFifthes(const std::wstring& str) const
{
	return MatchArray(fifthes, str);
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchDominants(const std::wstring& str) const
{
	return MatchArray(dominants, str);
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchTensions(const std::wstring& str) const
{
	return MatchArray(tensions, str);
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchOnChord(const std::wstring& str) const
{
	return MatchArray(onchords, str);
}