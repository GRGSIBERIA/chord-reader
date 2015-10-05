#include "gtest\gtest.h"
#include <ScoreTurner.hpp>
#include <ScoreReader.hpp>
using namespace score::score;

TEST(TestScoreTurner, read)
{
	auto score = ScoreReader::Load("..\\autumn leaves.xml");
	ScoreTurner turn(score, 4);
}