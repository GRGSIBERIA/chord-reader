#include "gtest\gtest.h"
#include <Beat.hpp>

void TestBeatSimple(const std::wstring& str)
{
	score::score::Beat part(4);

	part.PushBack(str);

	const auto& c = part.At(0);

	EXPECT_EQ(c->root.Name(), str);
}

TEST(TestBeat, simple)
{
	TestBeatSimple(L"C");
	TestBeatSimple(L"D");
	TestBeatSimple(L"Db");
}