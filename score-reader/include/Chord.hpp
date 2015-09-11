#pragma once
#include <string>
#include <vector>
#include <memory>

#include "ChordConstruction.hpp"

namespace score
{
	class ChordFactory;

	// コードのベースクラス
	class Chord
	{
		std::wstring chordName;	// コード名

		chord::RootPtr root;
		chord::TonePtr tone;
		chord::FifthPtr fifth;
		chord::DominantPtr dominant;
		chord::TensionPtr tensions;

	public:
		friend ChordFactory;

		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};

	typedef std::shared_ptr<Chord> ChordPtr;
}