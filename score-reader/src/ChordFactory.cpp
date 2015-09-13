#include "ChordFactory.hpp"

score::chord::ChordPtr score::chord::ChordFactory::CreateChord(const std::wstring& str)
{
	const static score::chord::ChordConstructions consts;

	auto ch = score::chord::ChordPtr(
		new score::chord::Chord(str, 
		(const score::chord::Root&)consts.MatchRoots(str), 
		(const score::chord::Tone&)consts.MatchTones(str), 
		(const score::chord::Fifth&)consts.MatchFifthes(str), 
		(const score::chord::Dominant&)consts.MatchDominants(str), 
		(const score::chord::Tension&)consts.MatchTensions(str), 
		(const score::chord::OnChord&)consts.MatchOnChords(str)));

	return ch;
}