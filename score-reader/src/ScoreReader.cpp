#include "ScoreReader.hpp"
#include <exception>
using namespace score::reader;

void ScoreReader::CollectParts(const tinyxml2::XMLElement* part)
{
	for (auto p = part; part != nullptr; p = part->NextSiblingElement("part"))
	{
		const int times = p->IntAttribute("repeat");
		if (times > 0)
		{
			for (int i = 0; i < times; ++i)
			{

			}
		}
		else
		{

		}
	}
}

ScoreReader::ScoreReader(const std::string& path)
{
	if (doc.LoadFile(path.c_str()) != tinyxml2::XMLError::XML_SUCCESS)
		throw std::exception((std::string("File not found: ") + path).c_str());

	const auto score = doc.FirstChildElement("chord-score")->FirstChildElement("score")->FirstChildElement("part");
	CollectParts(score);
}