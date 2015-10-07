#include "ChordScore.hpp"
#include <xml\tinyxml2.h>
#include <cstdlib>
#include <cstring>
using namespace score::score;

std::wstring widen(const std::string &src) {
	wchar_t *wcs = new wchar_t[src.length() + 1];
	mbstowcs(wcs, src.c_str(), src.length() + 1);
	std::wstring retval = wcs;
	delete[] wcs;
	return retval;
}

void ChordScore::CollectHeader(const tinyxml2::XMLElement* header)
{
	const std::wstring title = widen(header->FirstChildElement("title")->GetText());
	const std::wstring key = widen(header->FirstChildElement("key")->GetText());
	
	const auto rhythm = header->FirstChildElement("rhythm");
	const int beat = rhythm->IntAttribute("beat");
	const int note = rhythm->IntAttribute("note");

	this->header = HeaderPtr(new Header(title, key, beat, note));
}

void ChordScore::CollectScore(const tinyxml2::XMLElement* score)
{

}

ChordScore::ChordScore(const std::string& path)
{
	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(path.c_str()) != tinyxml2::XMLError::XML_SUCCESS)
		throw std::exception((std::string("File not found: ") + path).c_str());

	const auto root = doc.FirstChildElement("chord-score");

	const auto header = root->FirstChildElement("header");
	const auto score = root->FirstChildElement("score");

	CollectHeader(header);
	CollectScore(score);
}