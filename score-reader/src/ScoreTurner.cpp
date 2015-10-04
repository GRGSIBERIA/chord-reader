#include "ScoreTurner.hpp"
using namespace score::score;

ScoreTurner::ScoreTurner(const Score::_PPtr& score, const int rythm) 
	: rythm(rythm), partNum(0), keyNum(0), measureNum(0), chordNum(0), beat(0), ptr(score), score(*score), manager(*score)
{

}