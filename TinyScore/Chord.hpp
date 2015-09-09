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

		chord::Tone tone;						// 調性
		chord::Fifth fifth;					// 第五度
		chord::Dominant dominant;				// 属七音
		std::vector<chord::Tension> tensions;	// テンションノート

	public:
		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};
}