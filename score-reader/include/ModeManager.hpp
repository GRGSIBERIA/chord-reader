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
			void PushBack(const std::wstring& key) {
				if (std::find_if(begin(), end(), [key](const scale::KeyChordModalizer& m) { return key == m.KeyName(); }) == end())
					emplace_back(key);
			}
			
			// キーから探す
			const const_iterator Find(const std::wstring& key) const;

			const const_iterator Parallel(const std::wstring& key) const;	// 同主調
		};
	}
}