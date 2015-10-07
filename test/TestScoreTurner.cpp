#include "gtest\gtest.h"
#include <ScoreTurner.hpp>
#include <ScoreReader.hpp>
using namespace score::score;

auto sscore = ScoreReader::Load("..\\autumn leaves.xml");

ScoreTurner CreateScoreTurner()
{
	return ScoreTurner(sscore);
}

TEST(TestScoreTurner, count_test)
{
	ScoreTurner turn(sscore);

	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), true);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), true);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), true);
}

void TestMeasure(const ScoreTurner& turn, const std::wstring& str)
{
	const auto& measure = turn.CurrentMeasure();
	EXPECT_EQ(measure.Chord(0).Name(), str);
}

void NextTurn(ScoreTurner& turn)
{
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), true);
}

TEST(TestScoreTurner, next_measure)
{
	auto turn = CreateScoreTurner();

	TestMeasure(turn, L"Cm7");

	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), false);
	EXPECT_EQ(turn.Count(), true);

	TestMeasure(turn, L"F7");
	NextTurn(turn);
	TestMeasure(turn, L"BbM7");
	NextTurn(turn);
	TestMeasure(turn, L"EbM7");
	NextTurn(turn);
	TestMeasure(turn, L"Am7-5");
	NextTurn(turn);
	TestMeasure(turn, L"D7-9");
	NextTurn(turn);
	TestMeasure(turn, L"Gm");
	NextTurn(turn);
	TestMeasure(turn, L"Gm");
	NextTurn(turn);
	TestMeasure(turn, L"Cm7");	// ƒp[ƒg‚ª•Ï‚í‚Á‚ÄA‚Ì‚É–ß‚é
}

TEST(TestScoreTurner, next_part)
{
	auto turn = CreateScoreTurner();
	turn.Count();
	std::vector<std::wstring> names = {
		L"Cm7", L"F7", L"BbM7", L"EbM7", L"Am7-5", L"D7-9", L"Gm", L"Gm",
		L"Cm7", L"F7", L"BbM7", L"EbM7", L"Am7-5", L"D7-9", L"Gm", L"Gm",
		L"D7", L"D7", L"Gm", L"Gm", L"Cm7", L"F7", L"BbM7", L"EbM7",
		L"Am7-5", L"D7-9", L"Gm", L"Gm", L"C", L"D7-9", L"Gm", L"Gm"
	};
	
	for (const auto& str : names)
	{
		TestMeasure(turn, str);
		NextTurn(turn);
	}

	EXPECT_EQ(turn.IsEnded(), true);
}