#include "xml\tinyxml2.h"
#include "gtest\gtest.h"

TEST(TestTinyXML, read)
{
	tinyxml2::XMLDocument doc;
	EXPECT_EQ(doc.LoadFile("../autumn leaves.xml"), tinyxml2::XMLError::XML_SUCCESS);
}