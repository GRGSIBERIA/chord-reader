#pragma once
#include "Scale.hpp"

namespace score
{
	namespace scale
	{
		typedef std::array<Scale, 7> ScalesOnModeTheory;

		/**
		* �X�P�[�����烂�[�h�������������邽�߂̃N���X
		*/
		class ModeTheory
		{
			ScalesOnModeTheory modeScales;

		public:
			ModeTheory(const Scale& scale);

			const Scale& GetScale(const int key, const int root, const int mode);
		};
	}
}