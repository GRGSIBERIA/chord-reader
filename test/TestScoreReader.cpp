#include "gtest\gtest.h"
#include <ScoreReader.hpp>
using namespace score::score;

TEST(TestScoreReader, read)
{
	const auto score = ScoreReader::Load("..\\autumn leaves.xml");
}

TEST(TestScoreReader, header)
{
	const auto score = ScoreReader::Load("..\\autumn leaves.xml");
	EXPECT_EQ(score->Title(), L"Autumn Leaves");
	EXPECT_EQ(score->Key(), L"Bb");
	EXPECT_EQ(score->Beat(), 4);
	EXPECT_EQ(score->Note(), 4);
}

TEST(TestScoreReader, part)
{
	const auto score = ScoreReader::Load("..\\autumn leaves.xml");

	EXPECT_EQ(score->Part(0).Name(), L"A");
	EXPECT_EQ(score->Part(1).Name(), L"A");
	EXPECT_EQ(score->Part(2).Name(), L"B");
	EXPECT_EQ(score->Part(3).Name(), L"C");
}

TEST(TestScoreReader, chord)
{
	const auto score = ScoreReader::Load("..\\autumn leaves.xml");
	const auto key = score->Part(0).Key(0);

	EXPECT_EQ(key.Measure(0).Chord(0).Name(), L"Cm7");
	EXPECT_EQ(key.Measure(1).Chord(0).Name(), L"F7");
	EXPECT_EQ(key.Measure(2).Chord(0).Name(), L"BbM7");
	EXPECT_EQ(key.Measure(3).Chord(0).Name(), L"EbM7");
}