#include "gtest\gtest.h"
#include <ChordConstruction.hpp>

TEST(TestChordConstructions, root_regex)
{
	const score::chord::ChordConstructions regs;
	const auto re = regs.roots[0].Regex();
	EXPECT_EQ(std::regex_match(L"Db", re), true);
	EXPECT_EQ(std::regex_match(L"Dbm7", re), true);
	EXPECT_EQ(std::regex_match(L"DbM7", re), true);
	EXPECT_EQ(std::regex_match(L"DbM7 on C", re), true);
}

TEST(TestChordConstructions, root_match)
{
	const score::chord::ChordConstructions regs;
	EXPECT_EQ(regs.MatchRoots(L"Db").Name(), L"Db");
	EXPECT_EQ(regs.MatchRoots(L"D#").Name(), L"D#");
	EXPECT_EQ(regs.MatchRoots(L"A#m7").Name(), L"A#");
}

TEST(TestChordConstructions, tone_match)
{
	const score::chord::ChordConstructions regs;
	EXPECT_EQ(regs.MatchTones(L"Dbm7").Name(), L"m");
}