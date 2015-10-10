#pragma once
#include "Property.hpp"

namespace score
{
	namespace string
	{
		// Œ·ƒNƒ‰ƒX
		class String
		{
			const int tuningByMidi;
			const int frets;

		public:
			String(const int tuningByMidiNoteNumber, const int frets) : tuningByMidi(tuningByMidiNoteNumber), frets(frets) {}

			GET_PROPERTY(const int, Tuning, tuningByMidi);
			GET_PROPERTY(const int, Frets, frets);
		};
	}
}