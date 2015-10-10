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

			// キーから追加
			void PushBack(const std::wstring& key);

			// キーから探す
			const Itr Find(const std::wstring& key) const;

			// 転調
			const Itr Parallel(const std::wstring& key) const;	// 同主調
			const Itr Relative(const std::wstring& key) const;	// 平行調
			const Itr Dominant(const std::wstring& key) const;	// 属調
			const Itr SubDominant(const std::wstring& key) const;	// 下属調
			const Itr MinorDominant(const std::wstring& key) const;	// 属調2
			const Itr MinorSubDominant(const std::wstring& key) const;	// 下属調2
		};
	}
}