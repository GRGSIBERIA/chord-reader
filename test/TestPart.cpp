#include "gtest\gtest.h"
#include <Part.hpp>

TEST(TestPart, simple)
{
	score::score::Part part;

	part.PushBack(L"C");

	const auto& c = part.At(0);

	EXPECT_EQ(c->root.Name(), L"C");
}