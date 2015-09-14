#include "ChordConstruction.hpp"

std::shared_ptr<score::chord::ChordConstructions> score::chord::ChordConstructions::_inst = nullptr;

const score::chord::ChordConstructions& score::chord::ChordConstructions::GetInstance()
{
	if (_inst == nullptr)
		_inst = std::shared_ptr<score::chord::ChordConstructions>(new score::chord::ChordConstructions());
	return *_inst;
}

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
		return none;
	return constructions[i];
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchRoots(const std::wstring& str) const
{
	return MatchArray(roots, str);
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchTones(const std::wstring& str) const
{
	const auto& tone = MatchArray(tones, str);
	static const score::chord::Tone maj(L"", 4, L"");
	if (tone.Name() == L"")
		return maj;
	return tone;
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchFifthes(const std::wstring& str) const
{
	const auto& fifth = MatchArray(fifthes, str);
	static const score::chord::Fifth fif(L"", 7, L"");
	if (fifth.Name() == L"")
		return fif;
	return fifth;
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchDominants(const std::wstring& str) const
{
	return MatchArray(dominants, str);
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchTensions(const std::wstring& str) const
{
	return MatchArray(tensions, str);
}

const score::chord::ConstructionBase& score::chord::ChordConstructions::MatchOnChords(const std::wstring& str) const
{
	return MatchArray(onchords, str);
}