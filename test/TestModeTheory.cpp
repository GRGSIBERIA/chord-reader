#include "gtest\gtest.h"
#include <ModeTheory.hpp>

using namespace score::scale;

ModeTheory theory(Scale(L"major", { 0, 2, 4, 5, 7, 9, 11 }), { 0, 2, 4, 6 });

void TestScale(const ModeScale& mode, const std::vector<int>& target)
{
	for (size_t i = 0; i < target.size(); ++i)
		EXPECT_EQ(mode.GetInterval(i), target[i]);
}

void TestAvoid(const ModeScale& mode, const std::vector<int>& target)
{
	const auto& avoids = mode.GetAvoids();
	for (size_t i = 0; i < avoids.size(); ++i)
		EXPECT_EQ(avoids[i], target[i]);
}

void TestTritone(const ModeScale& mode, const std::vector<int>& target)
{
	const auto& ttone = mode.GetTritones();
	for (size_t i = 0; i < ttone.size(); ++i)
		EXPECT_EQ(ttone[i], target[i]);
}

TEST(TestModeTheory, test_major)
{
	TestScale(theory.GetMode(0), { 0, 2, 4, 5, 7, 9, 11 });
	TestScale(theory.GetMode(1), { 0, 2, 3, 5, 7, 9, 10 });
	TestScale(theory.GetMode(2), { 0, 1, 3, 5, 7, 8, 10 });
	TestScale(theory.GetMode(3), { 0, 2, 4, 6, 7, 9, 11 });
	TestScale(theory.GetMode(4), { 0, 2, 4, 5, 7, 9, 10 });
	TestScale(theory.GetMode(5), { 0, 2, 3, 5, 7, 8, 10 });
	TestScale(theory.GetMode(6), { 0, 1, 3, 5, 6, 8, 10 });
}

TEST(TestModeTheory, test_avoid)
{
	TestTritone(theory.GetMode(0), {3});
	TestTritone(theory.GetMode(1), {5});
	TestTritone(theory.GetMode(2), {1});
	TestTritone(theory.GetMode(3), {3});
	TestTritone(theory.GetMode(4), {});
	TestTritone(theory.GetMode(5), {});
	TestTritone(theory.GetMode(6), {});
}

TEST(TestModeTheory, test_diatonic)
{
	EXPECT_EQ(theory.Diatonics[0].ChordTone(), L"M7");
	EXPECT_EQ(theory.Diatonics[1].ChordTone(), L"m7");
	EXPECT_EQ(theory.Diatonics[2].ChordTone(), L"m7");
	EXPECT_EQ(theory.Diatonics[3].ChordTone(), L"M7");
	EXPECT_EQ(theory.Diatonics[4].ChordTone(), L"7");
	EXPECT_EQ(theory.Diatonics[5].ChordTone(), L"m7");
	EXPECT_EQ(theory.Diatonics[6].ChordTone(), L"m7-5");
}