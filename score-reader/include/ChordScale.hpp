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
			const std::wstring key;
			const int scaleIndex;
			const int modeIndex;
			const chord::Chord& chord;

			const ModeModals& scale;
			const ModeModals& available;
			const ModeModals& usable;

		public:
			GET_PROPERTY(const std::wstring, Key, key);
			GET_PROPERTY(const int, ScaleIndex, scaleIndex);
			GET_PROPERTY(const int, ModeIndex, modeIndex);
			GET_PROPERTY(const chord::Chord&, Chord, chord);
			GET_PROPERTY(const ModeModals&, Scale, scale);
			GET_PROPERTY(const ModeModals&, Available, available);
			GET_PROPERTY(const ModeModals&, Usable, usable);

			ChordScale(const std::wstring& key, const chord::Chord& chord, const int scaleIndex, const int modeIndex, const ModeModals& scale, const ModeModals& available, const ModeModals& usable)
				: key(key), chord(chord), scaleIndex(scaleIndex), modeIndex(modeIndex), scale(scale), available(available), usable(usable) {}
		};
	}
}