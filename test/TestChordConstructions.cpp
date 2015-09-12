#include "gtest\gtest.h"
#include <ChordConstruction.hpp>
#include <map>
using namespace std;
using namespace score::chord;

const score::chord::ChordConstructions regs;

TEST(TestChordConstructions, root_regex)
{
	const score::chord::ChordConstructions regs;
	const auto re = regs.roots[0].Regex();
	EXPECT_EQ(std::regex_match(L"Db", re), true);
	EXPECT_EQ(std::regex_match(L"Dbm7", re), true);
	EXPECT_EQ(std::regex_match(L"DbM7", re), true);
	EXPECT_EQ(std::regex_match(L"DbM7 on C", re), true);
}

template <typename T>
void TestAll(const score::chord::ConstructionBase& (ChordConstructions::*func)(const std::wstring&) const, const T& targets)
{
	for (const auto& target : targets)
	{
		
	}
}

TEST(TestChordConstructions, root_match)
{
	for (const auto& root : regs.roots)
	{
		EXPECT_EQ(regs.MatchRoots(root.Name()).Name(), root.Name());
		for (const auto& tone : regs.tones)
		{
			EXPECT_EQ(regs.MatchRoots(root.Name() + tone.Name()).Name(), root.Name());
			for (const auto& dominant : regs.dominants)
			{
				EXPECT_EQ(regs.MatchRoots(root.Name() + tone.Name() + dominant.Name()).Name(), root.Name());
				for (const auto& tension : regs.tensions)
				{
					EXPECT_EQ(regs.MatchRoots(root.Name() + tone.Name() + dominant.Name() + L"(" + tension.Name() + L")").Name(), root.Name());
					for (const auto& fifth : regs.fifthes)
					{
						EXPECT_EQ(regs.MatchRoots(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")").Name(), root.Name());
						for (const auto& onchord : regs.onchords)
						{
							EXPECT_EQ(regs.MatchRoots(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L" on" + onchord.Name()).Name(), root.Name());
							EXPECT_EQ(regs.MatchRoots(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L"/" + onchord.Name()).Name(), root.Name());
							EXPECT_EQ(regs.MatchRoots(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L"(on" + onchord.Name() + L")").Name(), root.Name());
						}
					}
				}
			}
		}
	}

	EXPECT_EQ(regs.MatchRoots(L"XXX").Name(), L"");
	EXPECT_EQ(regs.MatchRoots(L"Asshole").Name(), L"A");
}

TEST(TestChordConstructions, tone_match)
{
	for (const auto& tone : regs.tones)
	{
		for (const auto& root : regs.roots)
		{
			EXPECT_EQ(regs.MatchTones(root.Name() + tone.Name()).Name(), tone.Name());
			for (const auto& dominant : regs.dominants)
			{
				EXPECT_EQ(regs.MatchTones(root.Name() + tone.Name() + dominant.Name()).Name(), tone.Name());
				for (const auto& tension : regs.tensions)
				{
					EXPECT_EQ(regs.MatchTones(root.Name() + tone.Name() + dominant.Name() + L"(" + tension.Name() + L")").Name(), tone.Name());
					for (const auto& fifth : regs.fifthes)
					{
						EXPECT_EQ(regs.MatchTones(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")").Name(), tone.Name());
						for (const auto& onchord : regs.onchords)
						{
							EXPECT_EQ(regs.MatchTones(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L" on" + onchord.Name()).Name(), tone.Name());
							EXPECT_EQ(regs.MatchTones(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L"/" + onchord.Name()).Name(), tone.Name());
							EXPECT_EQ(regs.MatchTones(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L"(on" + onchord.Name() + L")").Name(), tone.Name());
						}
					}
				}
			}
		}
	}
}

TEST(TestChordConstructions, fifth_match)
{
	for (const auto& fifth : regs.fifthes)
	{
		for (const auto& root : regs.roots)
		{
			EXPECT_EQ(regs.MatchFifthes(root.Name() + fifth.Name()).Name(), fifth.Name());
			for (const auto& tone : regs.tones)
			{
				EXPECT_EQ(regs.MatchFifthes(root.Name() + tone.Name() + fifth.Name()).Name(), fifth.Name());
				for (const auto& dominant : regs.dominants)
				{
					EXPECT_EQ(regs.MatchFifthes(root.Name() + tone.Name() + dominant.Name() + fifth.Name()).Name(), fifth.Name());
					for (const auto& tension : regs.tensions)
					{
						EXPECT_EQ(regs.MatchFifthes(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")").Name(), fifth.Name());
						for (const auto& onchord : regs.onchords)
						{
							EXPECT_EQ(regs.MatchFifthes(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L" on" + onchord.Name()).Name(), fifth.Name());
							EXPECT_EQ(regs.MatchFifthes(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L"/" + onchord.Name()).Name(), fifth.Name());
							EXPECT_EQ(regs.MatchFifthes(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L"(on" + onchord.Name() + L")").Name(), fifth.Name());
						}
					}
				}
			}
		}
	}
}

TEST(TestChordConstructions, dominant_match)
{
	for (const auto& dominant : regs.dominants)
	{
		if (dominant.Name() == L"") continue;
		for (const auto& root : regs.roots)
		{
			EXPECT_EQ(regs.MatchDominants(root.Name() + dominant.Name()).Name(), dominant.Name());
			for (const auto& fifth : regs.fifthes)
			{
				EXPECT_EQ(regs.MatchDominants(root.Name() + dominant.Name() + fifth.Name()).Name(), dominant.Name());
				for (const auto& tone : regs.tones)
				{
					EXPECT_EQ(regs.MatchDominants(root.Name() + tone.Name() + dominant.Name() + fifth.Name()).Name(), dominant.Name());
					for (const auto& tension : regs.tensions)
					{
						EXPECT_EQ(regs.MatchDominants(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")").Name(), dominant.Name());
						for (const auto& onchord : regs.onchords)
						{
							EXPECT_EQ(regs.MatchDominants(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L" on" + onchord.Name()).Name(), dominant.Name());
							EXPECT_EQ(regs.MatchDominants(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L"/" + onchord.Name()).Name(), dominant.Name());
							EXPECT_EQ(regs.MatchDominants(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L"(on" + onchord.Name() + L")").Name(), dominant.Name());
						}
					}
				}
			}
		}
	}
}

//TEST(TestChordConstructions, tension_match)
//{
//	TestAll(&ChordConstructions::MatchTensions, regs.tensions);
//}
//
//TEST(TestChordConstructions, onchord_match)
//{
//	TestAll(&ChordConstructions::MatchOnChord, regs.onchords);
//}