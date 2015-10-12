#pragma once
#include "Scale.hpp"
#include "Chord.hpp"
#include "Modal.hpp"
#include "Property.hpp"

namespace score
{
	namespace scale
	{
		typedef std::vector<ModeScale> ScalesOnModeTheory;
		typedef std::vector<chord::Chord> DiatonicChords;

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
			const ModeScale& GetMode(const Modal modal) const { return modeScales[(size_t)modal]; }

			GET_PROPERTY(const ScalesOnModeTheory&, Modes, modeScales);
			GET_PROPERTY(const DiatonicChords&, Diatonics, diatonics);

			//const Scale& GetScale(const int key, const int root, const int mode);
		};
	}
}