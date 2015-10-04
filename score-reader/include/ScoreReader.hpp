#pragma once
#include <string>
#include "xml\tinyxml2.h"
#include "Score.hpp"

namespace score
{
	namespace score
	{
		class ScoreReader
		{
			tinyxml2::XMLDocument doc;

			score::Score score;

			void CollectParts(const tinyxml2::XMLElement* part);
			Measure::_PPtr CollectChord(const tinyxml2::XMLElement* chord);
			Key::_PPtr CollectMeasure(const tinyxml2::XMLElement* measure, const std::wstring& keyStr);
			Part::_PPtr CollectKey(const tinyxml2::XMLElement* key, const std::wstring& partName);

		public:
			ScoreReader(const std::string& path);

			const score::Score& Score() const { return score; }
		};
	}
}