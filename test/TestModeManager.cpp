#include "gtest\gtest.h"
#include <ModeManager.hpp>
#include <ChordScore.hpp>
using namespace score::score;

score::score::ChordScore csb("..\\autumn leaves.xml");

TEST(TestModeManager, challenge)
{
	ModeManager mng(csb.Chords);

	auto t = mng.Find(L"Bb");
	EXPECT_EQ(t->KeyName, L"Bb");
}

TEST(TestModeManager, parallel)
{
	ModeManager mng(csb.Chords);

	auto t = mng.Parallel(L"Bb");
	EXPECT_EQ(t->KeyName, L"Bbm");
}

TEST(TestModeManager, relative)
{
	ModeManager mng(csb.Chords);

	EXPECT_EQ(mng.Relative(L"Bb")->KeyName, L"Gm");
}

TEST(TestModeManager, hoge)
{
	ModeManager mng(csb.Chords);

	const auto& b4 = mng.Find(L"Bb")->GetPrimaryAvailableScale(0);
	const auto& h = mng.Parallel(L"Bb")->GetPrimaryAvailableScale(0);
}