#include "gtest\gtest.h"
#include <score\ChordConstruction.hpp>

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
	const auto& Db = regs.MatchRoots(L"Db");
	EXPECT_EQ(Db.Name(), L"Db");
}