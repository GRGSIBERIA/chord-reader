#pragma once
#include "Modal.hpp"
#include "RelatedKey.hpp"
#include "ScaleDatabase.hpp"

namespace score
{
	namespace scale
	{
		// ����`��RelatedKey��������ꂽ�ꍇ�̗�O
		class UndefinedRelatedKeyException : public std::exception
		{
		public:
			UndefinedRelatedKeyException() : exception("�Ȃ񂩂�[�킩���") {}
		};

		// �������]��������
		class Modulation
		{
		private:
			static const scale::ChordScale ModalInterchange(const std::wstring& key, const int chordIndex, const RelatedKey related, const KeyChordModalizer& base);

		public:
			static const std::wstring Modulate(const RelatedKey relate, const std::wstring& key);
			static const std::wstring Parallel(const std::wstring& key);			// ���咲(I)
			static const std::wstring Relative(const std::wstring& key);			// ���s��(maj=VIm, min=III)
			static const std::wstring Dominant(const std::wstring& key);			// ����(V)
			static const std::wstring SubDominant(const std::wstring& key);			// ������(IV)
			static const std::wstring MinorDominant(const std::wstring& key);		// ����2(maj=IIIm, min=VII)
			static const std::wstring MinorSubDominant(const std::wstring& key);	// ������2(maj=IIm, min=VI)

			// �J�ڂ������R�[�h��I�Ƃ��āCV�̃R�[�h�����߂�C2���h�~�i���g
			static const scale::ChordScale SecondaryDominant(const std::wstring& targetChord, const bool useMinor);

			// ���[�_���C���^�[�`�F���W
			static const scale::ChordScale ModalInterchange(const std::wstring& key, const std::wstring& chord, const RelatedKey related);
			static const scale::ChordScale ModalInterchange(const std::wstring& key, const size_t scaleIndex, const RelatedKey related);

			// ���R�[�h�C�㗝�h�~�i���g�C��ʓI�ɂ�V�̑㗝
			static const scale::ChordScale SubstituteDominant(const std::wstring& key, const std::wstring& chord);
		};
	}
}