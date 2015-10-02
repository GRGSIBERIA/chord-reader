#include "ScoreReader.hpp"
#include <exception>
using namespace score::reader;

ScoreReader::ScoreReader(const std::string& path)
{
	if (doc.LoadFile(path.c_str()) != tinyxml2::XMLError::XML_SUCCESS)
		throw std::exception((std::string("File not found: ") + path).c_str());

	doc.FirstChildElement();
}