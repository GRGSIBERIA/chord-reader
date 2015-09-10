#pragma once
#include "Chord.hpp"

namespace score
{
	class ChordFactory
	{
	public:
		static ChordPtr MakeChord(const std::wstring& str);
	};
}