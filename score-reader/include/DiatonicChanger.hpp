#pragma once
#include "ScaleDatabase.hpp"
#include "Modulation.hpp"

namespace score
{
	namespace chord
	{
		// �㗝�R�[�h��T�����߂̃N���X
		class DiatonicChanger
		{
		public:
			// �J�ڂ������R�[�h��I�Ƃ��āCV�̃R�[�h�����߂�
			static const scale::ChordScale SecondaryDominant(const std::wstring& targetChord, const bool useMinor);

			// ���咲�ؗp
			static const scale::ChordScale ModalInterchange(const std::wstring& key, const std::wstring& chord, const RelatedKey related);
		};
	}
}