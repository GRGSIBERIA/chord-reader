#pragma once
#include <string>

#include "Tone.hpp"

namespace cr
{
	class Chord
	{
		std::wstring chordName;	//!< コード名
		chord::Tone tone;		//!< メジャー/マイナー

	public:
		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};
}