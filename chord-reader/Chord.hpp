#pragma once
#include <string>

namespace cr
{
	class Chord
	{
		std::wstring chordName;

	public:
		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};
}