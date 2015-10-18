#include "gtest\gtest.h"
#include <iostream>
#include <Modulation.hpp>
using namespace score::scale;
using namespace std;

TEST(TestModulation, parallel)
{
	std::vector<std::wstring> strs = { L"C", L"D", L"E", L"F", L"G", L"A", L"B" };
	std::vector<std::wstring> min;

	for (const auto& str : strs)
		EXPECT_EQ(Modulation::Parallel(str), str + L"m");

	for (auto& str : strs) min.push_back(str + L"m");

	for (size_t i = 0; i < strs.size(); ++i)
		EXPECT_EQ(Modulation::Parallel(min[i]), strs[i]);

	EXPECT_EQ(Modulation::Parallel(L"C#"), L"C#m");
	EXPECT_EQ(Modulation::Parallel(L"Db"), L"Dbm");
}

TEST(TestModulation, dominant)
{
	EXPECT_EQ(Modulation::Dominant(L"C"), L"G");
	EXPECT_EQ(Modulation::Dominant(L"D"), L"A");
	EXPECT_EQ(Modulation::Dominant(L"Cm"), L"Gm");
	EXPECT_EQ(Modulation::Dominant(L"Dm"), L"Am");
}

TEST(TestModulation, relative)
{
	EXPECT_EQ(Modulation::Relative(L"C"), L"Am");
	EXPECT_EQ(Modulation::Relative(L"D"), L"Bm");
	EXPECT_EQ(Modulation::Relative(L"Cm"), L"E");
	EXPECT_EQ(Modulation::Relative(L"Dm"), L"F#");
}

TEST(TestModulation, subdominant)
{
	EXPECT_EQ(Modulation::SubDominant(L"C"), L"F");
	EXPECT_EQ(Modulation::SubDominant(L"D"), L"G");
	EXPECT_EQ(Modulation::SubDominant(L"Cm"), L"Fm");
	EXPECT_EQ(Modulation::SubDominant(L"Dm"), L"Gm");
}

TEST(TestModulation, secondary)
{
	EXPECT_EQ(Modulation::SecondaryDominant(L"CM7", false).Chord.Name(), L"G7");
	EXPECT_EQ(Modulation::SecondaryDominant(L"Dm7", false).Chord.Name(), L"A7");
	EXPECT_EQ(Modulation::SecondaryDominant(L"Em7", false).Chord.Name(), L"B7");
	EXPECT_EQ(Modulation::SecondaryDominant(L"FM7", false).Chord.Name(), L"C7");
	EXPECT_EQ(Modulation::SecondaryDominant(L"G7", false).Chord.Name(), L"D7");
	EXPECT_EQ(Modulation::SecondaryDominant(L"Am7", false).Chord.Name(), L"E7");
	EXPECT_EQ(Modulation::SecondaryDominant(L"Bm7-5", false).Chord.Name(), L"Gb7");
}

TEST(TestModulation, interchange)
{
	Modulation::ModalInterchange(L"", L"", RelatedKey::Parallel);
}