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

			const scale::ModeModals& GetScale(const std::wstring& key, const std::wstring& chord)
			{

			}
		};
	}
}