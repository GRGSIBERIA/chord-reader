#pragma once
#include "Property.hpp"

namespace score
{
	namespace inst
	{
		typedef int MidiNoteNumber;

		// Œ·ƒNƒ‰ƒX
		class String
		{
			const MidiNoteNumber tuning;
			const int frets;

		public:
			String(const MidiNoteNumber tuningByMidiNoteNumber, const int frets) : tuning(tuningByMidiNoteNumber), frets(frets) {}

			GET_PROPERTY(const int, Tuning, tuningByMidi);
			GET_PROPERTY(const int, Frets, frets);
		};
	}
}