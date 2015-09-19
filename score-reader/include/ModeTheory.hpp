#pragma once
#include "Scale.hpp"

namespace score
{
	namespace scale
	{
		typedef std::vector<ModeScale> ScalesOnModeTheory;

		/**
		* �X�P�[�����烂�[�h�������������邽�߂̃N���X
		*/
		class ModeTheory
		{
			ScalesOnModeTheory modeScales;
			ScaleIndices chordTones;

			void MakeModeScale(const int i, const Scale& scale);

		public:
			ModeTheory(const Scale& scale, const ScaleIndices& chordTones);

			const ModeScale& GetMode(const size_t index) const { return modeScales[index]; }

			//const Scale& GetScale(const int key, const int root, const int mode);
		};
	}
}