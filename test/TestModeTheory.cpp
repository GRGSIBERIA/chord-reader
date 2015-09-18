#include "gtest\gtest.h"
#include <ModeTheory.hpp>

using namespace score::scale;

TEST(TestModeTheory, test_mejor)
{
	ModeTheory theory(Scale(L"major", {0, 2, 4, 5, 7, 9, 11}));

	const auto& mode = theory.GetMode(0);
	std::vector<int> target = { 0, 2, 4, 5, 7, 9, 11 };

	for (int i = 0; i < target.size(); ++i)
		EXPECT_EQ(mode.GetInterval(i), target[i]);
}