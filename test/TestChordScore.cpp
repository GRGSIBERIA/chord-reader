#include "gtest/gtest.h"
#include <ChordScore.hpp>
using namespace score::score;

ChordScore score("..\\autumn leaves.xml");

TEST(TestChordScore, header)
{
	EXPECT_EQ(score.Header.Title, L"Autumn Leaves");
	EXPECT_EQ(score.Header.Key, L"Bb");
	EXPECT_EQ(score.Header.Note, 4);
	EXPECT_EQ(score.Header.Beat, 4);
}

TEST(TestChordScore, Chords)
{
	std::vector<std::wstring> test = { 
		L"Cm7", L"F7", L"BmM7", L"EbM7",
		L"Am7-5", L"D7-9", L"Gm", L"Gm",
		L"Cm7", L"F7", L"BmM7", L"EbM7",
		L"Am7-5", L"D7-9", L"Gm", L"Gm",
		L"D7", L"D7", L"Gm", L"Gm",
		L"Cm7", L"F7", L"BmM7", L"EbM7",
		L"Am7-5", L"D7-9", L"Gm", L"Gm",
		L"C", L"Cm6", L"D7-9", L"Gm", L"Gm"
	};

	for (size_t i = 0; i < test.size(); ++i)
	{
		EXPECT_EQ(test[i], score.Chords[i].Chord().Name());
	}
}