#include "ScoreReader.hpp"
#include <exception>
using namespace score::reader;

ScoreReader::ScoreReader(const std::string& path)
{
	if (doc.LoadFile(path.c_str()) != tinyxml2::XMLError::XML_SUCCESS)
		throw std::exception((std::string("File not found: ") + path).c_str());

	const auto& rootP = *doc.FirstChildElement("chord-score");
	const auto& scoreP = *rootP.FirstChildElement("score");
	
	for (const auto part = scoreP.FirstChildElement("part"); part != nullptr; part->NextSiblingElement("part"))
	{
		if (part->Attribute("repeat") != nullptr)
		{
			int times = part->IntAttribute("repeat");
		}
		else
		{

		}
	}
}