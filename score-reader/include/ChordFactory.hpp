#pragma once
#include "Chord.hpp"

namespace score
{
	namespace chord
	{
		class ChordFactory
		{
		public:
			static ChordPtr CreateChord(const std::wstring& str);
			static Chord CreateChord(const int root, const int third, const int fifth, const int sevens=-1);
		};
	}
}