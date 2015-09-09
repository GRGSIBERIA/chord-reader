#pragma once
#include <string>

#include "Tone.hpp"

namespace cr
{
	class Chord
	{
		std::wstring chordName;	//!< �R�[�h��
		chord::Tone tone;		//!< ���W���[/�}�C�i�[

	public:
		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};
}