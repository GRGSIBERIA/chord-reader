#include "gtest\gtest.h"
#include <score\ChordConstruction.hpp>

TEST(TestChordConstructions, instance)
{
	const score::chord::ChordConstructions regs;
	EXPECT_EQ(std::regex_match(L"Db", regs.roots[0].Regex()), true);
}