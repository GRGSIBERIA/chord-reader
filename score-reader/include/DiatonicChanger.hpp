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
			static const scale::ChordScale SecondaryDominant(const std::wstring& targetChord);
		};
	}
}