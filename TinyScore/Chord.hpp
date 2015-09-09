#pragma once
#include <string>
#include <vector>

#include "ChordConstruction.hpp"

namespace ts
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