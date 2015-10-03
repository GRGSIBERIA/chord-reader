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

		public:
			ScoreReader(const std::string& path);
		};
	}
}