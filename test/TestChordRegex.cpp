#include "gtest\gtest.h"
#include <score\ChordConstruction.hpp>

TEST(TestChordRegex, instance)
{
	const score::chord::ChordRegex regs;
	EXPECT_EQ(std::regex_match(L"Db", regs.roots[0]), true);
}