#include "ChordFactory.hpp"

score::ChordPtr score::ChordFactory::CreateChord(const std::wstring& str)
{
	auto ch = score::ChordPtr(new score::Chord(str));
	const static score::chord::ChordConstructions consts;

	return ch;
}