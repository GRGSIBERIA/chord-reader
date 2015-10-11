#pragma once
#include <vector>
#include "String.hpp"

namespace score
{
	namespace inst
	{
		// ŠyŠíƒNƒ‰ƒX
		class Instrument
		{
			std::vector<String> strings;

		public:
			Instrument(const int frets, const std::vector<MidiNoteNumber>& tunings) {
				strings.reserve(tunings.size());
				for (const auto tuning : tunings)
					strings.emplace_back(tuning, frets);
			}

			GET_PROPERTY(const std::vector<String>&, Strings, strings);
		};
	}
}