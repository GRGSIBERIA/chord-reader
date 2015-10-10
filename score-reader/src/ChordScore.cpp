#include "ChordScore.hpp"
#include <xml\tinyxml2.h>
#include <cstdlib>
#include <cstring>
using namespace score::score;

std::wstring widen(const std::string &src) {
	wchar_t *wcs = new wchar_t[src.length() + 1];
	mbstowcs_s(nullptr, wcs, src.length() + 1, src.c_str(), src.length() + 1);
	std::wstring retval(wcs);
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

	this->header = HeaderPtr(new score::Header(title, key, beat, note));
}

#define FOR_ELEM(PARENT, CHILD) for (auto CHILD = PARENT->FirstChildElement("##CHILD"); CHILD != nullptr; CHILD = CHILD->NextSiblingElement("##CHILD"))

const int CountElements(const tinyxml2::XMLElement* head)
{
	int retval = 0;
	FOR_ELEM(head, tail)
	{
		retval++;
	}
	return retval;
}

const std::wstring MakeDash(const int repeat)
{
	std::wstring retval = L"";
	for (int i = 0; i < repeat; ++i)
		retval += L"'";
	return retval;
}

void ChordScore::CollectScore(const tinyxml2::XMLElement* score)
{
	for (auto part = score->FirstChildElement("part"); part != nullptr; part = part->NextSiblingElement("part"))
	{
		const auto partName = widen(part->Attribute("name"));
		int repeat = part->IntAttribute("repeat");
		if (repeat == 0) repeat = 1;

		for (int i = 0; i < repeat; ++i)
		{
			for (auto key = part->FirstChildElement("key"); key != nullptr; key = key->NextSiblingElement("key"))
			{
				const auto keyCode = widen(key->Attribute("code"));

				for (auto measure = key->FirstChildElement("measure"); measure != nullptr; measure = measure->NextSiblingElement("measure"))
				{
					const auto count = CountElements(measure->FirstChildElement("chord"));
					const auto time = 4 >> (count - 1);

					for (auto chord = measure->FirstChildElement("chord"); chord != nullptr; chord = chord->NextSiblingElement("chord"))
					{
						const auto chordName = widen(chord->GetText());
						chords.emplace_back(partName + MakeDash(i), keyCode, chordName, time);
					}
				}
			}
		}
	}
}

void CheckLocale()
{
	static bool localed = false;
	if (!localed)
	{
		localed = true;
		setlocale(LC_CTYPE, "");
	}
}

ChordScore::ChordScore(const std::string& path)
{
	CheckLocale();

	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(path.c_str()) != tinyxml2::XMLError::XML_SUCCESS)
		throw std::exception((std::string("File not found: ") + path).c_str());

	const auto root = doc.FirstChildElement("chord-score");

	const auto header = root->FirstChildElement("header");
	const auto score = root->FirstChildElement("score");

	CollectHeader(header);
	CollectScore(score);
}