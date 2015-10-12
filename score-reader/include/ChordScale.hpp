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

		// コードとスケールの組み
		class ChordScale
		{
			const int modeIndex;
			const chord::Chord& chord;
			const ModeModals& scale;
		public:
			GET_PROPERTY(const int, ModeIndex, modeIndex);
			GET_PROPERTY(const chord::Chord&, Chord, chord);
			GET_PROPERTY(const ModeModals&, Scale, scale);

			ChordScale(const chord::Chord& chord, const int modeIndex, const ModeModals& scale)
				: chord(chord), scale(scale), modeIndex(modeIndex) {}
		};
	}
}