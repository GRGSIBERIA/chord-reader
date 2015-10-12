#pragma once
#include "ScaleDatabase.hpp"

namespace score
{
	namespace chord
	{
		// �㗝�R�[�h��T�����߂̃N���X
		class DiatonicChanger
		{
		public:
			static const scale::KeyChordModalizer& SecondaryDominant(const std::wstring& key, const std::wstring& chord);
		};
	}
}