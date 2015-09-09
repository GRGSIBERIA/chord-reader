#include "Recognizer.hpp"
#include <regex>

score::ChordPtr score::chord::Recognizer::MakeChord(const std::wstring& chordName)
{
	auto chord = score::ChordPtr(new score::Chord(chordName));

	return chord;
}