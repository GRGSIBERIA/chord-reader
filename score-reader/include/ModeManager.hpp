#pragma once
#include "KeyChordModalizer.hpp"
#include "ChordUnit.hpp"

namespace score
{
	namespace score
	{
		class ModeManager : public std::vector<scale::KeyChordModalizer>
		{
		public:
			ModeManager(const ChordUnitArray chords);

			// �L�[����ǉ�
			void PushBack(const std::wstring& key);
			
			// �L�[����T��
			const scale::KeyChordModalizer& Find(const std::wstring& key) const;
		};
	}
}