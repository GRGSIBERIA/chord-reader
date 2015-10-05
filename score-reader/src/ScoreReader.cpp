#include "ScoreReader.hpp"
#include "Measure.hpp"
#include "ChordFactory.hpp"
#include <exception>
#include <cstdlib>
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

const std::wstring ConvertWidenText(const std::string& str)
{
	std::wstring wstr;
	widen(str, wstr);
	return wstr;
}

const ChordPtr ReadChord(const tinyxml2::XMLElement* c)
{
	auto chordStr = ConvertWidenText(c->GetText());

	return ChordFactory::CreateChord(chordStr);
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

Key::_PPtr ScoreReader::CollectMeasure(const tinyxml2::XMLElement* measure, const std::wstring& keyStr)
{
	auto keyPtr = Key::Instantiate(keyStr);

	for (auto m = measure; m != nullptr; m = m->NextSiblingElement("measure"))
	{
		const auto chord = m->FirstChildElement("chord");
		auto measurePtr = CollectChord(chord);

		keyPtr->PushBack(measurePtr);
	}

	return keyPtr;
}

Part::_PPtr ScoreReader::CollectKey(const tinyxml2::XMLElement* key, const std::wstring& partName)
{
	auto partPtr = Part::Instantiate(partName);

	for (auto k = key; k != nullptr; k = k->NextSiblingElement("key"))
	{
		const auto keyStr = ConvertWidenText(key->Attribute("code"));
		const auto measure = k->FirstChildElement("measure");
		const auto keyPtr = CollectMeasure(measure, keyStr);
		partPtr->PushBack(keyPtr);
	}

	return partPtr;
}

void ScoreReader::CollectParts(Score::_PPtr& score, const tinyxml2::XMLElement* part)
{
	const auto key = part->FirstChildElement("key");
	const int times = part->IntAttribute("repeat");
	const auto partName = ConvertWidenText(part->Attribute("name"));

	if (times > 0)
	{
		for (int i = 0; i < times; ++i)
		{
			const auto partPtr = CollectKey(key, partName);
			score->PushBack(partPtr);
		}
	}
	else
	{
		const auto partPtr = CollectKey(key, partName);
		score->PushBack(partPtr);
	}
}

Score::_PPtr InstantiateScore(const tinyxml2::XMLElement* header)
{
	const auto title = ConvertWidenText(header->FirstChildElement("title")->GetText());
	const auto key = ConvertWidenText(header->FirstChildElement("key")->GetText());
	const auto rhythm = header->FirstChildElement("rhythm");

	return Score::Instantiate(title, key);
}

const Score::_PPtr ScoreReader::Load(const std::string& path)
{
	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(path.c_str()) != tinyxml2::XMLError::XML_SUCCESS)
		throw std::exception((std::string("File not found: ") + path).c_str());

	setlocale(LC_CTYPE, "");

	const auto root = doc.FirstChildElement("chord-score");
	const auto part = root->FirstChildElement("score")->FirstChildElement("part");
	const auto header = root->FirstChildElement("header");

	auto score = InstantiateScore(header);

	for (auto p = part; p != nullptr; p = p->NextSiblingElement("part"))
	{
		CollectParts(score, p);
	}

	return score;
}