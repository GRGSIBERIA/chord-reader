#include "xml\tinyxml2.h"
#include "gtest\gtest.h"

TEST(TestTinyXML, read)
{
	tinyxml2::XMLDocument doc;
	EXPECT_EQ(doc.LoadFile("..\\autumn leaves.xml"), tinyxml2::XMLError::XML_SUCCESS);
}

void TestString(const char* a, const char* b)
{
	EXPECT_EQ(std::string(a), std::string(b));
}

TEST(TestTinyXML, read_score)
{
	tinyxml2::XMLDocument doc;
	EXPECT_EQ(doc.LoadFile("..\\autumn leaves.xml"), tinyxml2::XMLError::XML_SUCCESS);

	const auto root = doc.FirstChildElement("chord-score");
	const auto score = root->FirstChildElement("score");

	TestString(score->Name(), "score");
}

TEST(TestTinyXML, read_part)
{
	tinyxml2::XMLDocument doc;
	EXPECT_EQ(doc.LoadFile("..\\autumn leaves.xml"), tinyxml2::XMLError::XML_SUCCESS);
	const auto part = doc.FirstChildElement("chord-score")->FirstChildElement("score")->FirstChildElement("part");

	EXPECT_EQ(part->IntAttribute("repeat"), 2);

	const auto next = part->NextSiblingElement("part");

	EXPECT_EQ(next->IntAttribute("repeat"), 0);
}

int CountElements(const tinyxml2::XMLElement* elem, const char* str)
{
	int count = 0;
	for (auto p = elem; p != nullptr; p = p->NextSiblingElement(str))
		++count;
	return count;
}

TEST(TestBeat, count)
{
	tinyxml2::XMLDocument doc;
	EXPECT_EQ(doc.LoadFile("..\\autumn leaves.xml"), tinyxml2::XMLError::XML_SUCCESS);
	const auto part = doc.FirstChildElement("chord-score")->FirstChildElement("score")->FirstChildElement("part");

	EXPECT_EQ(CountElements(part, "part"), 3);
}