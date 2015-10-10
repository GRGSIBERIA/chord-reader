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
			const const_iterator Find(const int& key) const;
			const const_iterator Find(const scale::Modal& key) const;

			const const_iterator Parallel(const std::wstring& key) const;	// 同主調
			const const_iterator Relative(const std::wstring& key) const;	// 平行調
			const const_iterator Dominant(const std::wstring& key) const;	// 属調
			const const_iterator SubDominant(const std::wstring& key) const;	// 下属調
			const const_iterator MinorDominant(const std::wstring& key) const;	// 属調2
			const const_iterator MinorSubDominant(const std::wstring& key) const;	// 下属調2
		};
	}
}