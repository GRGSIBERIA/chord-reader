#pragma once
#include "Chord.hpp"

namespace score
{
	class ChordFactory
	{
	public:
		static ChordPtr CreateChord(const std::wstring& str);
	};
}