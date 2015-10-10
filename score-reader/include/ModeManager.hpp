#pragma once
#include "KeyChordModalizer.hpp"
#include "ChordUnit.hpp"

namespace score
{
	namespace score
	{
		class ModeManager
		{
			std::vector<scale::KeyChordModalizer> modes;

		public:
			typedef std::vector<scale::KeyChordModalizer>::const_iterator Itr;

			ModeManager(const ChordUnitArray chords);

			// �L�[����ǉ�
			void PushBack(const std::wstring& key);

			// �L�[����T��
			const Itr Find(const std::wstring& key) const;

			// �]��
			const Itr Parallel(const std::wstring& key) const;	// ���咲
			const Itr Relative(const std::wstring& key) const;	// ���s��
			const Itr Dominant(const std::wstring& key) const;	// ����
			const Itr SubDominant(const std::wstring& key) const;	// ������
			const Itr MinorDominant(const std::wstring& key) const;	// ����2
			const Itr MinorSubDominant(const std::wstring& key) const;	// ������2
		};
	}
}