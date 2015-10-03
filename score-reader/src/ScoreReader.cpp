#include "ScoreReader.hpp"
#include "Measure.hpp"
#include "ChordFactory.hpp"
#include <exception>
#include <cstdlib>
using namespace score::reader;
using namespace score::score;
using namespace score::chord;

void widen(const std::string &src, std::wstring &dest) {
	wchar_t *wcs = new wchar_t[src.length() + 1];
	size_t buf;
	mbstowcs_s(&buf, wcs, src.length() + 1, src.c_str(), src.length() + 1);
	dest = wcs;
	delete[] wcs;
}

int CountElements(const tinyxml2::XMLElement* elem, const char* str)
{
	int count = 0;
	for (auto p = elem; p != nullptr; p = p->NextSiblingElement(str))
		++count;
	return count;
}

const ChordPtr ReadChord(const tinyxml2::XMLElement* c)
{
	auto chordStr = std::string(c->GetText());
	std::wstring widedStr;
	widen(chordStr, widedStr);

	return ChordFactory::CreateChord(widedStr);
}

Measure::_PPtr ScoreReader::CollectChord(const tinyxml2::XMLElement* chord)
{
	int count = CountElements(chord, "chord");

	auto measurePtr = Measure::Instantiate(count);

	for (auto c = chord; c != nullptr; c = c->NextSiblingElement("chord"))
	{
		measurePtr->PushBack(ReadChord(c));
	}

	return measurePtr;
}

Part::_PPtr ScoreReader::CollectMeasure(const tinyxml2::XMLElement* measure)
{
	auto partPtr = Part::Instantiate();

	for (auto m = measure; m != nullptr; m = m->NextSiblingElement("measure"))
	{
		const auto chord = m->FirstChildElement("chord");
		auto measurePtr = CollectChord(chord);

		partPtr->PushBack(measurePtr);
	}

	return partPtr;
}

void ScoreReader::CollectParts(const tinyxml2::XMLElement* part)
{
	const auto measure = part->FirstChildElement("measure");
	const int times = part->IntAttribute("repeat");

	if (times > 0)
	{
		for (int i = 0; i < times; ++i)
		{
			const auto partPtr = CollectMeasure(measure);
			score.PushBack(partPtr);
		}
	}
	else
	{
		const auto partPtr = CollectMeasure(measure);
		score.PushBack(partPtr);
	}
}

ScoreReader::ScoreReader(const std::string& path)
{
	if (doc.LoadFile(path.c_str()) != tinyxml2::XMLError::XML_SUCCESS)
		throw std::exception((std::string("File not found: ") + path).c_str());

	setlocale(LC_CTYPE, "");

	const auto part = doc.FirstChildElement("chord-score")->FirstChildElement("score")->FirstChildElement("part");

	for (auto p = part; p != nullptr; p = p->NextSiblingElement("part"))
	{
		CollectParts(p);
	}
}