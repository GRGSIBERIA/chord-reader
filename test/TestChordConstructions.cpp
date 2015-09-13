#include "gtest\gtest.h"
#include <ChordConstruction.hpp>
#include <map>
using namespace std;
using namespace score::chord;

const score::chord::ChordConstructions& regs = score::chord::ChordConstructions::GetInstance();

TEST(TestChordConstructions, root_match)
{
#ifdef TEST_CHORD
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
							EXPECT_EQ(regs.MatchRoots(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L"(on" + onchord.Name() + L")").Name(), root.Name());
						}
					}
				}
			}
		}
	}
#endif

	EXPECT_EQ(regs.MatchRoots(L"XXX").Name(), L"");
	EXPECT_EQ(regs.MatchRoots(L"Asshole").Name(), L"A");
}

TEST(TestChordConstructions, tone_match)
{
#ifdef TEST_CHORD
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
							EXPECT_EQ(regs.MatchTones(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L"/" + onchord.Name()).Name(), tone.Name());
						}
					}
				}
			}
		}
	}
#endif
}

TEST(TestChordConstructions, fifth_match)
{
#ifdef TEST_CHORD
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
						}
					}
				}
			}
		}
	}
#endif
}

TEST(TestChordConstructions, dominant_match)
{
#ifdef TEST_CHORD
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
							EXPECT_EQ(regs.MatchDominants(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + L"(on" + onchord.Name() + L")").Name(), dominant.Name());
						}
					}
				}
			}
		}
	}
#endif
}

TEST(TestChordConstructions, tension_match)
{
#ifdef TEST_CHORD
	for (const auto& tension : regs.tensions)
	{
		if (tension.Name() == L"") continue;
		const auto t = std::wstring(L"(") + tension.Name() + L")";

		for (const auto& root : regs.roots)
		{
			EXPECT_EQ(regs.MatchTensions(root.Name() + t).Name(), tension.Name());
			for (const auto& fifth : regs.fifthes)
			{
				EXPECT_EQ(regs.MatchTensions(root.Name() + fifth.Name() + t).Name(), tension.Name());
				for (const auto& dominant : regs.dominants)
				{
					EXPECT_EQ(regs.MatchTensions(root.Name() + dominant.Name() + fifth.Name() + t).Name(), tension.Name());
					for (const auto& tone : regs.tones)
					{
						EXPECT_EQ(regs.MatchTensions(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + t).Name(), tension.Name());
						for (const auto& onchord : regs.onchords)
						{
							EXPECT_EQ(regs.MatchTensions(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + t + L"/" + onchord.Name()).Name(), tension.Name());
						}
					}
				}
			}
		}
	}
#endif
}

TEST(TestChordConstructions, onchord_match)
{
#ifdef TEST_CHORD
	for (const auto& onchord : regs.onchords)
	{
		if (onchord.Name() == L"") continue;
		const auto t = std::wstring(L"on") + onchord.Name();

		for (const auto& root : regs.roots)
		{
			EXPECT_EQ(regs.MatchOnChords(root.Name() + t).Name(), onchord.Name());
			for (const auto& fifth : regs.fifthes)
			{
				EXPECT_EQ(regs.MatchOnChords(root.Name() + fifth.Name() + t).Name(), onchord.Name());
				for (const auto& dominant : regs.dominants)
				{
					EXPECT_EQ(regs.MatchOnChords(root.Name() + dominant.Name() + fifth.Name() + t).Name(), onchord.Name());
					for (const auto& tone : regs.tones)
					{
						EXPECT_EQ(regs.MatchOnChords(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + t).Name(), onchord.Name());
						for (const auto& tension : regs.tensions)
						{
							EXPECT_EQ(regs.MatchOnChords(root.Name() + tone.Name() + dominant.Name() + fifth.Name() + L"(" + tension.Name() + L")" + t).Name(), onchord.Name());
						}
					}
				}
			}
		}
	}
#endif
}