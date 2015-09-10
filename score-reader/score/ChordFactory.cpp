#include "score\ChordFactory.hpp"

score::ChordPtr score::ChordFactory::CreateChord(const std::wstring& str)
{
	auto ch = score::ChordPtr(new score::Chord(str));
	const static score::chord::ChordRegex regex;

	return ch;
}