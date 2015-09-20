#include <ScaleTheory.hpp>
#include "gtest\gtest.h"

using namespace score::scale;

ScaleTheory major({ 0, 2, 4, 5, 7, 9, 11 });

void TestScale(size_t num, const ScaleIntervals& interval)
{
	for (size_t i = 0; i < interval.size(); ++i)
		EXPECT_EQ(major.GetScale(num)[i], interval[i]);
}

TEST(TestScaleTheory, test_major_scale)
{
	TestScale(0,  { 0, 2, 4, 5, 7, 9, 11 });
	TestScale(1,  { 0, 1, 3, 5, 6, 8, 10 });
	TestScale(2,  { 1, 2, 4, 6, 7, 9, 11 });
	TestScale(3,  { 0, 2, 3, 5, 7, 8, 10 });
	TestScale(4,  { 1, 3, 4, 6, 8, 9, 11 });
	TestScale(5,  { 0, 2, 4, 5, 7, 9, 10 });
	TestScale(6,  { 1, 3, 5, 6, 8, 10,11 });
	TestScale(7,  { 0, 2, 4, 6, 7, 9, 11 });
	TestScale(8,  { 0, 1, 3, 5, 7, 8, 10 });
	TestScale(9,  { 1, 2, 4, 6, 8, 9, 11 });
	TestScale(10, { 0, 2, 3, 5, 7, 9, 10 });
	TestScale(11, { 1, 3, 4, 6, 8, 10, 11 });
}