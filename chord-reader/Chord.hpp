#pragma once
#include <string>

namespace cr
{
	namespace chord
	{
		class Chord
		{
			std::wstring chordName;

		public:
			Chord(const std::wstring& chordName)
				: chordName(chordName) {}
		};
	}
}