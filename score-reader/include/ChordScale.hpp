#pragma once
#include <vector>
#include "Chord.hpp"
#include "Property.hpp"

namespace score
{
	namespace scale
	{
		typedef std::vector<int> ModeModals;
		typedef std::vector<ModeModals> ModeModalScales;
		typedef std::vector<ModeModalScales> ModesOnScale;

		class KeyChordModalizer;

		// コードとスケールの組み
		class ChordScale
		{
			const int scaleIndex;
			const int modeIndex;
			const chord::Chord& chord;
			const ModeModals& scale;
			const ModeModals& available;
			const KeyChordModalizer& modalizer;

		public:
			GET_PROPERTY(const int, ScaleIndex, scaleIndex);
			GET_PROPERTY(const int, ModeIndex, modeIndex);
			GET_PROPERTY(const chord::Chord&, Chord, chord);
			GET_PROPERTY(const ModeModals&, Scale, scale);
			GET_PROPERTY(const ModeModals&, Available, available);

			ChordScale(const chord::Chord& chord, const int scaleIndex, const int modeIndex, const ModeModals& scale, const ModeModals& available, const KeyChordModalizer& modalizer)
				: chord(chord), scale(scale), scaleIndex(scaleIndex), modeIndex(modeIndex), available(available), modalizer(modalizer) {}

			const ChordScale Mode(const int i) const;
		};
	}
}