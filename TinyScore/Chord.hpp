#pragma once
#include <string>

#include "Tone.hpp"

namespace cr
{
	// �R�[�h�̃x�[�X�N���X
	class Chord
	{
		std::wstring chordName;	// �R�[�h��


	public:
		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};
}