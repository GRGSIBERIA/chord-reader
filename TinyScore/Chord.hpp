#pragma once
#include <string>

#include "Tone.hpp"

namespace cr
{
	// �R�[�h�̃x�[�X�N���X
	class Chord
	{
		std::wstring chordName;	// �R�[�h��
		chord::Tone tone;		// ���W���[/�}�C�i�[

	public:
		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};

	// �O�a��
	class Triad : public Chord
	{

	};

	// �l�a��
	class Tetrad : public Chord
	{

	};
}