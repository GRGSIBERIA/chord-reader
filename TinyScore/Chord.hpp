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

		chord::Tone tone;						// ����
		chord::Fifth fifth;					// ��ܓx
		chord::Dominant dominant;				// ������
		std::vector<chord::Tension> tensions;	// �e���V�����m�[�g

	public:
		Chord(const std::wstring& chordName)
			: chordName(chordName) {}
	};
}