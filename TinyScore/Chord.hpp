#pragma once
#include <string>
#include <vector>

#include "ChordConstruction.hpp"

namespace ts
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