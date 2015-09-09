#pragma once
#include "Chord.hpp"

namespace score
{
	namespace chord
	{
		class Recognizer
		{
		public:
			Recognizer() {}

			ChordPtr MakeChord(const std::wstring& str);
		};
	}
}