#include "gtest\gtest.h"
#include "Global.hpp"
#include <ModeManager.hpp>
#include <ChordScore.hpp>
using namespace score::score;

TEST(TestModeManager, test)
{
	ModeManager mng(cs.Chords);

	auto t = mng.Find(L"Bb");
}