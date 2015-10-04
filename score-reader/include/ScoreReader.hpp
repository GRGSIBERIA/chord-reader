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
			static void CollectParts(Score::_PPtr& score, const tinyxml2::XMLElement* part);
			static Measure::_PPtr CollectChord(const tinyxml2::XMLElement* chord);
			static Key::_PPtr CollectMeasure(const tinyxml2::XMLElement* measure, const std::wstring& keyStr);
			static Part::_PPtr CollectKey(const tinyxml2::XMLElement* key, const std::wstring& partName);

		public:
			static const Score::_PPtr Load(const std::string& path);
		};
	}
}