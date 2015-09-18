#include "gtest\gtest.h"
#include <ModeTheory.hpp>

using namespace score::scale;

void TestScale(const Scale& mode, const std::vector<int>& target)
{
	for (size_t i = 0; i < target.size(); ++i);
		//EXPECT_EQ(mode.GetInterval(i), target[i]);
}

TEST(TestModeTheory, test_major)
{
	ModeTheory theory(Scale(L"major", { 0, 2, 4, 5, 7, 9, 11 }), { 0, 2, 4, 6 });

	TestScale(theory.GetMode(0), { 0, 2, 4, 5, 7, 9, 11 });
	TestScale(theory.GetMode(1), { 0, 2, 3, 5, 7, 9, 10 });
	TestScale(theory.GetMode(2), { 0, 1, 3, 5, 7, 8, 10 });
	TestScale(theory.GetMode(3), { 0, 2, 4, 6, 7, 9, 11 });
	TestScale(theory.GetMode(4), { 0, 2, 4, 5, 7, 9, 10 });
	TestScale(theory.GetMode(5), { 0, 2, 3, 5, 7, 8, 10 });
	TestScale(theory.GetMode(6), { 0, 1, 3, 5, 6, 8, 10 });
}