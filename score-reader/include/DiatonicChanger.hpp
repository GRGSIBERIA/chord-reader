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
			static const scale::ChordScale SecondaryDominant(const std::wstring& targetChord);
		};
	}
}