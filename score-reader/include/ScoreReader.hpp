#pragma once
#include <string>
#include "xml\tinyxml2.h"
#include "Score.hpp"

namespace score
{
	namespace reader
	{
		class ScoreReader
		{
			tinyxml2::XMLDocument doc;

			score::Score score;

			void CollectParts(const tinyxml2::XMLElement* part);
			score::Measure::_PPtr CollectChord(const tinyxml2::XMLElement* chord);
			score::Part::_PPtr CollectMeasure(const tinyxml2::XMLElement* measure);

		public:
			ScoreReader(const std::string& path);

			const score::Score& Score() const { return score; }
		};
	}
}