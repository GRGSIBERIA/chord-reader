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
		public:
			Measure(const int count) : count(count) {}

			const int Count() const { return count; }

			static _PPtr Instantiate(const int count) { return _PPtr(new Measure(count)); }

			const chord::Chord& Chord(const size_t i) const { return *elem[i]; }
		};
	}
}