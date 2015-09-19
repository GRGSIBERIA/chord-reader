#pragma once
#include "Scale.hpp"
#include "Chord.hpp"

namespace score
{
	namespace scale
	{
		typedef std::vector<ModeScale> ScalesOnModeTheory;
		typedef std::vector<score::chord::Chord> DiatonicChords;

		/**
		* スケールからモードを自動生成するためのクラス
		*/
		class ModeTheory
		{
			ScalesOnModeTheory modeScales;
			ScaleIndices chordTones;
			DiatonicChords diatonics;

			void MakeModeScale(const int i, const Scale& scale);
			void BuildingModeScales(const Scale& scale);
			void BuildingDiatonicChords();

		public:
			ModeTheory(const Scale& scale, const ScaleIndices& chordTones);

			const size_t Size() const { return modeScales.size(); }

			const ModeScale& GetMode(const size_t index) const { return modeScales[index]; }
			const score::chord::Chord& GetDiatonic(const size_t index) const { return diatonics[index]; }

			//const Scale& GetScale(const int key, const int root, const int mode);
		};
	}
}