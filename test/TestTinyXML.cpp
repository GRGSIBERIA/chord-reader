#include "xml\tinyxml2.h"
#include "gtest\gtest.h"

TEST(TestTinyXML, read)
{
	tinyxml2::XMLDocument doc;
	EXPECT_EQ(doc.LoadFile("..\\autumn leaves.xml"), tinyxml2::XMLError::XML_SUCCESS);
}

TEST(TestTinyXML, read_score)
{
	tinyxml2::XMLDocument doc;
	EXPECT_EQ(doc.LoadFile("..\\autumn leaves.xml"), tinyxml2::XMLError::XML_SUCCESS);

	tinyxml2::XMLElement* root = doc.FirstChildElement("chord-score");
	const auto score = doc.FirstChildElement("score");

	EXPECT_EQ(score->Name(), "score");
}

TEST(TestTinyXML, read_part)
{
	tinyxml2::XMLDocument doc;
	EXPECT_EQ(doc.LoadFile("..\\autumn leaves.xml"), tinyxml2::XMLError::XML_SUCCESS);
	//const auto score = doc.FirstChildElement("chord-score")->FirstChildElement("score");

	//const auto part = score->FirstChildElement("part");
	//EXPECT_EQ(part->IntAttribute("repeat"), 2);
}