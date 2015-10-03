#include "gtest\gtest.h"
#include <ScoreReader.hpp>
using namespace score::score;

TEST(TestScoreReader, read)
{
	ScoreReader r("..\\autumn leaves.xml");
	const auto& score = r.Score();

	score.At(0);
}