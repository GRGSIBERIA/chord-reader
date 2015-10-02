#pragma once
#include <string>
#include "xml\tinyxml2.h"

namespace score
{
	namespace reader
	{
		class ScoreReader
		{
			tinyxml2::XMLDocument doc;

		public:
			ScoreReader(const std::string& path);
		};
	}
}