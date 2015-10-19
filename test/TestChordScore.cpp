#include "gtest/gtest.h"
#include <ChordScore.hpp>
#include <ChordUnit.hpp>
using namespace score::score;

score::score::ChordScore cs("..\\autumn leaves.xml");

TEST(TestChordScore, header)
{
	EXPECT_EQ(cs.Header.Title, L"Autumn Leaves");
	EXPECT_EQ(cs.Header.Key, L"Bb");
	EXPECT_EQ(cs.Header.Note, 4);
	EXPECT_EQ(cs.Header.Beat, 4);
}

TEST(TestChordScore, Chords)
{
	std::vector<std::wstring> test = { 
		L"Cm7", L"F7", L"BbM7", L"EbM7",
		L"Am7-5", L"D7-9", L"Gm", L"Gm",
		L"Cm7", L"F7", L"BbM7", L"EbM7",
		L"Am7-5", L"D7-9", L"Gm", L"Gm",
		L"D7", L"D7", L"Gm", L"Gm",
		L"Cm7", L"F7", L"BbM7", L"EbM7",
		L"Am7-5", L"D7-9", L"Gm", L"Gm",
		L"C", L"Cm6", L"D7-9", L"Gm", L"Gm"
	};

	for (size_t i = 0; i < test.size(); ++i)
	{
		EXPECT_EQ(test[i], cs.Chords[i].Chord.Name());
	}
}

TEST(TestChordScore, next_part)
{
	auto ad = cs.Chords.NextPart(cs.Chords.begin());
	EXPECT_EQ(ad->Part, L"A'");

	auto b = cs.Chords.NextPart(ad);
	EXPECT_EQ(b->Part, L"B");

	auto c = cs.Chords.NextPart(b);
	EXPECT_EQ(c->Part, L"C");
}

ChordUnitArray::Itr TestKey(ChordUnitArray::Itr k, const std::wstring& str)
{
	EXPECT_EQ(k->Key, str);
	return cs.Chords.NextKey(k);
}

TEST(TestChordScore, next_key)
{
	std::vector<std::wstring> s = { L"Bb", L"Gm", L"Bb", L"Gm", L"G", L"Gm", L"Bb", L"Gm", L"Bb" };

	auto k = cs.Chords.cbegin();
	for (const auto& str : s)
		k = TestKey(k, str);
}

TEST(TestChordScore, chord_unit)
{
	const auto k = cs.Chords.cbegin();
	const auto hoge = k->Scale(0);
}