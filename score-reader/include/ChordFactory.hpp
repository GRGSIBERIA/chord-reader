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
		};
	}
}