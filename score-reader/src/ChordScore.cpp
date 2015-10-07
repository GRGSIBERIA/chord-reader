#include "ChordScore.hpp"
#include <xml\tinyxml2.h>
using namespace score::score;

ChordScore::ChordScore(const std::string& path)
{
	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(path.c_str()) != tinyxml2::XMLError::XML_SUCCESS)
		throw std::exception((std::string("File not found: ") + path).c_str());
}