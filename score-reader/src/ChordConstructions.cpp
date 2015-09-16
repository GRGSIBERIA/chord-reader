#include "ChordConstruction.hpp"
using namespace score::chord;

std::shared_ptr<ChordConstructions> ChordConstructions::_inst = ChordConstructions::GetPtr();

const ChordConstructions& ChordConstructions::GetInstance()
{
	return *GetPtr();
}

const std::shared_ptr<ChordConstructions> ChordConstructions::GetPtr()
{
	if (_inst == nullptr)
		_inst = std::shared_ptr<ChordConstructions>(new ChordConstructions());
	return _inst;
}

template <typename T>
const ConstructionBase& ChordConstructions::MatchArray(const T& constructions, const std::wstring& str) const
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

const ConstructionBase& ChordConstructions::MatchRoots(const std::wstring& str) const
{
	return MatchArray(roots, str);
}

const ConstructionBase& ChordConstructions::MatchTones(const std::wstring& str) const
{
	const auto& tone = MatchArray(tones, str);
	static const Tone maj(L"", 4, L"");
	if (tone.Name() == L"")
		return maj;
	return tone;
}

const ConstructionBase& ChordConstructions::MatchFifthes(const std::wstring& str) const
{
	const auto& fifth = MatchArray(fifthes, str);
	static const Fifth fif(L"", 7, L"");
	if (fifth.Name() == L"")
		return fif;
	return fifth;
}

const ConstructionBase& ChordConstructions::MatchDominants(const std::wstring& str) const
{
	return MatchArray(dominants, str);
}

const ConstructionBase& ChordConstructions::MatchTensions(const std::wstring& str) const
{
	return MatchArray(tensions, str);
}

const ConstructionBase& ChordConstructions::MatchOnChords(const std::wstring& str) const
{
	return MatchArray(onchords, str);
}