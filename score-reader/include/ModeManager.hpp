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

			// キーから追加
			void PushBack(const std::wstring& key);
			
			// キーから探す
			const scale::KeyChordModalizer& Find(const std::wstring& key) const;
		};
	}
}