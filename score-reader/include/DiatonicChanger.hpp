#pragma once
#include "ScaleDatabase.hpp"
#include "Modulation.hpp"

namespace score
{
	namespace chord
	{
		// 代理コードを探すためのクラス
		class DiatonicChanger
		{
		public:
			// 遷移したいコードをIとして，Vのコードを求める
			static const scale::ChordScale SecondaryDominant(const std::wstring& targetChord, const bool useMinor);

			// 同主調借用
			static const scale::ChordScale ModalInterchange(const std::wstring& key, const std::wstring& chord, const RelatedKey related);
		};
	}
}