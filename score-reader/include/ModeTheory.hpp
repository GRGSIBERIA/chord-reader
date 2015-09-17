#pragma once
#include "Scale.hpp"

namespace score
{
	namespace scale
	{
		typedef std::vector<Scale> ScalesOnModeTheory;
		typedef std::vector<std::vector<int>> AvoidNotes;

		/**
		* スケールからモードを自動生成するためのクラス
		*/
		class ModeTheory
		{
			ScalesOnModeTheory modeScales;
			AvoidNotes avoids;

			void CreateModeScales(const Scale& scale);

		public:
			ModeTheory(const Scale& scale);

			//const Scale& GetScale(const int key, const int root, const int mode);
		};
	}
}