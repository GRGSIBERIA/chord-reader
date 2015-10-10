#include "gtest\gtest.h"
#include <ModeManager.hpp>
#include <ChordScore.hpp>
using namespace score::score;

score::score::ChordScore csb("..\\autumn leaves.xml");

TEST(TestModeManager, challenge)
{
	ModeManager mng(csb.Chords);

	auto t = mng.Find(L"Bb");
	EXPECT_EQ(t->KeyName(), L"Bb");
}

TEST(TestModeManager, test_parallel)
{
	ModeManager mng(csb.Chords);

	auto t = mng.Parallel(L"Bb");
	EXPECT_EQ(t->KeyName(), L"Bbm");
}