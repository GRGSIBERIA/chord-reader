#pragma once
#include "Scale.hpp"

namespace score
{
	namespace scale
	{
		typedef std::array<Scale, 7> ScalesOnModeTheory;

		/**
		* スケールからモードを自動生成するためのクラス
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