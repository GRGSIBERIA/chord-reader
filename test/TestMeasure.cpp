#include "gtest\gtest.h"
#include <Measure.hpp>
#include <ChordFactory.hpp>

void TestBeatSimple(const std::wstring& str)
{
	score::score::Measure part(1);

	const auto chord = score::chord::ChordFactory::CreateChord(str);
	part.PushBack(chord);

	const auto& c = part.Chord(0);

	EXPECT_EQ(c.root.Name(), str);
}

TEST(TestMeasure, simple)
{
	TestBeatSimple(L"C");
	TestBeatSimple(L"D");
	TestBeatSimple(L"Db");
}