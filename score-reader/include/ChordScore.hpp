#pragma once
#include <string>
#include <vector>
#include "ChordUnit.hpp"
#include "Header.h"

namespace score
{
	namespace score
	{
		class ChordScore
		{
			std::vector<ChordUnit> chords;
			HeaderPtr header;

			void CollectHeader(const tinyxml2::XMLElement* header);
			void CollectScore(const tinyxml2::XMLElement* score);

		public:
			ChordScore(const std::string& path);
		};
	}
}