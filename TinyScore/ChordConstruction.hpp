#pragma once

namespace ts
{
	namespace chord
	{
		// ����
		enum class Tone
		{
			Major,	// ���W���[
			Minor	// �}�C�i�[
		};

		// �掵�x
		enum class Dominant
		{
			None,			// �Ȃ�
			Seven,			// 7th
			MajorSeven,		// M7
			DiminishedSeven	// dim7
		};

		// ��ܓx
		enum class Fifth
		{
			Perfect,	// ���S5�x
			Diminished,	// -5th
			Augumented	// +5th
		};

		// �e���V�����m�[�g
		enum class Tension
		{
			FlatNine,		// -9
			Nine,			//  9
			SharpNine,		// +9
			Eleven,			//  11
			SharpEleven,	// +11
			FlatThirteen,	// -13
			Thirteen,		//  13
		};
	}
}