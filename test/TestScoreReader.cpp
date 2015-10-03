#include "gtest\gtest.h"
#include <ScoreReader.hpp>
using namespace score::reader;

TEST(TestScoreReader, read)
{
	ScoreReader r("..\\autumn leaves.xml");
	const auto& score = r.Score();

	score.At(0)->At(0)->At(0)->root.Name();
}