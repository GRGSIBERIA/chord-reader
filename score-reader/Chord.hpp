#pragma once
#include <string>
#include <vector>
#include <memory>

#include "ChordConstruction.hpp"

namespace score
{
	// コードのベースクラス
	class Chord
	{
		std::wstring chordName;	// コード名

		chord::TonePtr tone;
		chord::FifthPtr fifth;
		chord::DominantPtr dominant;
		std::vector<chord::TensionPtr> tensions;

	public:
		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};
}