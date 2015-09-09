#pragma once
#include <string>

#include "Tone.hpp"

namespace cr
{
	// コードのベースクラス
	class Chord
	{
		std::wstring chordName;	// コード名


	public:
		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};
}