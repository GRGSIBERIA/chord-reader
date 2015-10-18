#pragma once
#include "Modal.hpp"

namespace score
{
	namespace scale
	{
		enum class RelatedKey
		{
			Parallel,			// ���咲
			Relative,			// ���s��
			Dominant,			// ����
			Subdominant,		// ������
			MinorDominant,		// ���]����
			MinorSubdominant	// ���]������
		};

		// ����`��RelatedKey��������ꂽ�ꍇ�̗�O
		class UndefinedRelatedKeyException : public std::exception
		{
		public:
			UndefinedRelatedKeyException() : exception("�Ȃ񂩂�[�킩���") {}
		};

		// �������]��������
		class Modulation
		{
		public:
			static const std::wstring Modulate(const RelatedKey relate, const std::wstring& key);
			static const std::wstring Parallel(const std::wstring& key);			// ���咲(I)
			static const std::wstring Relative(const std::wstring& key);			// ���s��(maj=VIm, min=III)
			static const std::wstring Dominant(const std::wstring& key);			// ����(V)
			static const std::wstring SubDominant(const std::wstring& key);			// ������(IV)
			static const std::wstring MinorDominant(const std::wstring& key);		// ����2(maj=IIIm, min=VII)
			static const std::wstring MinorSubDominant(const std::wstring& key);	// ������2(maj=IIm, min=VI)
		};
	}
}