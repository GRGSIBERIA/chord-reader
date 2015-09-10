#include "ChordFactory.hpp"
#include <regex>

score::ChordPtr score::ChordFactory::MakeChord(const std::wstring& chordName)
{
	auto ch = score::ChordPtr(new score::Chord(chordName));
	
	

	return ch;
}