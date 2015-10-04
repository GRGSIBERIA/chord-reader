#pragma once
#include <map>
#include "KeyChordModalizer.hpp"
#include "Score.hpp"

namespace score
{
	namespace score
	{
		class ScaleManager
		{
			typedef std::shared_ptr<scale::KeyChordModalizer> KCMPtr;
			std::map<std::wstring, KCMPtr> keys;

		public:
			ScaleManager(const Score& score);

			// アベイラブルスケールの一覧を取得する
			const scale::ModeModalScales& GetScale(const std::wstring& key, const std::wstring& chord) { return keys[key]->GetAvailables(chord); }

			// 現在のコードのモードインデックスを取得する
			const int GetIndexOnScale(const std::wstring& key, const std::wstring& chord) { return keys[key]->ModeIndex(chord); }
		};
	}
}