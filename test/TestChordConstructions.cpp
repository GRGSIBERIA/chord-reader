#include "gtest\gtest.h"
#include <ChordConstruction.hpp>
using namespace std;

TEST(TestChordConstructions, root_regex)
{
	const score::chord::ChordConstructions regs;
	const auto re = regs.roots[0].Regex();
	EXPECT_EQ(std::regex_match(L"Db", re), true);
	EXPECT_EQ(std::regex_match(L"Dbm7", re), true);
	EXPECT_EQ(std::regex_match(L"DbM7", re), true);
	EXPECT_EQ(std::regex_match(L"DbM7 on C", re), true);
}

const std::array<std::wstring, 17> GetRoots()
{
	return{ {
		L"C#", L"D#", L"F#", L"G#", L"A#", L"Bb", L"Ab", L"Gb", L"Eb", L"Db", L"C", L"D", L"E", L"F", L"G", L"A", L"B"
			} };
}

const std::vector<std::wstring> GetExtensions()
{
	return{ {
		L"", L"m", L"7", L"M7", L"m7", L"mM7", L"m7-5", L"sus4", L"sus6", L"6", L"7sus4",
		L"(9)", L"(11)", L"(13)", L"(b9)", L"(b11)", L"(b13)", L"(#9)", L"(#11)", L"(#13)",
		L"m(9)", L"m(11)", L"m(13)", L"m(b9)", L"m(b11)", L"m(b13)", L"m(#9)", L"m#(11)", L"m(#13)"
			} };
}

void MatchRoot(const score::chord::ChordConstructions& regs, const std::array<std::wstring, 17> roots, const std::wstring ext)
{
	for (const auto& root : roots)
	{
		EXPECT_EQ(regs.MatchRoots(root + ext).Name(), root);
	}
}

TEST(TestChordConstructions, root_match)
{
	const score::chord::ChordConstructions regs;
	const auto roots = GetRoots();
	const auto extensions = GetExtensions();
	
	MatchRoot(regs, roots, L"");

	for (const auto& ext : extensions)
		MatchRoot(regs, roots, ext);
	
	for (const auto& ext : extensions)
	{
		for (const auto& root : roots)
			MatchRoot(regs, roots, ext + L"on " + root);
	}

	EXPECT_EQ(regs.MatchRoots(L"XXX").Name(), L"Idefinite");
	EXPECT_EQ(regs.MatchRoots(L"Asshole").Name(), L"A");
}

const std::vector<std::wstring> GetAfterTone()
{
	return{ {
		L"7", L"M7", L"7-5", L"sus4", L"7sus4", L"sus6", L"6"
			} };
}

TEST(TestChordConstructions, tone_match)
{
	const score::chord::ChordConstructions regs;
	const auto roots = GetRoots();
	const auto afters = GetAfterTone();

	for (const auto& root : roots)
	{
		for (const auto& after : afters)
		{
			EXPECT_EQ(regs.MatchTones(root + after).Name(), L"");
			EXPECT_EQ(regs.MatchTones(root + L"m" + after).Name(), L"m");
		}
	}
}

TEST(TestChordConstructions, fifth_match)
{
	const score::chord::ChordConstructions regs;

	for (const auto& f : regs.fifthes)
	{
		for (const auto& root : regs.roots)
		{
			for (const auto& dominant : regs.dominants)
			{
				for (const auto& tone : regs.tones)
				{
					EXPECT_EQ(regs.MatchFifthes(root.Name() + tone.Name() + f.Name() + dominant.Name()).Name(), f.Name());
				}
			}
		}
	}
}