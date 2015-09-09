#pragma once
#include <string>

#include "Tone.hpp"

namespace cr
{
	// コードのベースクラス
	class Chord
	{
		std::wstring chordName;	// コード名
		chord::Tone tone;		// メジャー/マイナー

	public:
		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};

	// 三和音
	class Triad : public Chord
	{

	};

	// 四和音
	class Tetrad : public Chord
	{

	};
}