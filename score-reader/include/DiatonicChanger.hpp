#pragma once
#include "ScaleDatabase.hpp"

namespace score
{
	namespace chord
	{
		// 代理コードを探すためのクラス
		class DiatonicChanger
		{
		public:
			static const scale::KeyChordModalizer& SecondaryDominant(const std::wstring& key, const std::wstring& chord);
		};
	}
}