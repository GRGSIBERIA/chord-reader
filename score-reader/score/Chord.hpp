#pragma once
#include <string>
#include <vector>
#include <memory>

#include "ChordConstruction.hpp"

namespace score
{
	class Recognizer;

	// コードのベースクラス
	class Chord
	{
		friend Recognizer;

		std::wstring chordName;	// コード名

		chord::TonePtr tone;
		chord::FifthPtr fifth;
		chord::DominantPtr dominant;
		std::vector<chord::TensionPtr> tensions;

	public:
		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};

	typedef std::shared_ptr<Chord> ChordPtr;
}