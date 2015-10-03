#include "gtest\gtest.h"
#include <Measure.hpp>

void TestBeatSimple(const std::wstring& str)
{
	score::score::Measure part(4);

	part.PushBack(str);

	const auto& c = part.At(0);

	EXPECT_EQ(c->root.Name(), str);
}

TEST(TestMeasure, simple)
{
	TestBeatSimple(L"C");
	TestBeatSimple(L"D");
	TestBeatSimple(L"Db");
}