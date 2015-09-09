#pragma once
#include <string>
#include <vector>
#include <memory>

#include "ChordConstruction.hpp"

namespace score
{
	// �R�[�h�̃x�[�X�N���X
	class Chord
	{
		std::wstring chordName;	// �R�[�h��

		chord::TonePtr tone;
		chord::FifthPtr fifth;
		chord::DominantPtr dominant;
		std::vector<chord::TensionPtr> tensions;

	public:
		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};
}