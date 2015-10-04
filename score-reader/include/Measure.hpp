#pragma once
#include "Chord.hpp"
#include "ConstructionBase.hpp"
#include "ChordFactory.hpp"

namespace score
{
	namespace score
	{
		class Measure : public ConstructionBase < Measure, chord::Chord >
		{
			int count;
			int tick_per_chord;

		public:
			Measure(const int count) : count(count), tick_per_chord(4 / count) {}

			const int Count() const { return count; }

			static _PPtr Instantiate(const int count) { return _PPtr(new Measure(count)); }

			const chord::Chord& Chord(const size_t i) const { return *elem[i]; }

			const int BeatPerChord() const { return tick_per_chord; }	// 1ƒR[ƒh‚ ‚½‚è‚Ì””
		};
	}
}