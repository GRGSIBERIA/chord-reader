#include "gtest\gtest.h"
#include <Part.hpp>

void TestPartSimple(const std::wstring& str)
{
	score::score::Part part;

	part.PushBack(str);

	const auto& c = part.At(0);

	EXPECT_EQ(c->root.Name(), str);
}

TEST(TestPart, simple)
{
	TestPartSimple(L"C");
	TestPartSimple(L"D");
	TestPartSimple(L"Db");
}