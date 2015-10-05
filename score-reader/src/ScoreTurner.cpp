#include "ScoreTurner.hpp"
using namespace score::score;

ScoreTurner::ScoreTurner(const Score::_PPtr& score, const int rythm) 
	: rythm(rythm), ptr(score), score(*score), manager(*score)
{
	Initialize();
}

void ScoreTurner::Initialize()
{
	partNum = 0; keyNum = 0; measureNum = 0; count = 0;
	endFlag = false;
}

const bool ScoreTurner::IsEnded() const
{
	return endFlag;
}

void ScoreTurner::Restart()
{
	Initialize();
}

bool ScoreTurner::Count()
{
	if (count++ >= rythm)
	{
		count = 0;

		if (measureNum++ >= score.Part(partNum).Key(keyNum).Size())
		{
			measureNum = 0;

			if (keyNum++ >= score.Part(partNum).Size())
			{
				keyNum = 0;

				if (partNum++ >= score.Size())
				{
					partNum = 0;
					endFlag = true;
				}
			}
		}
		
		return true;
	}
	return false;
}

const Measure& ScoreTurner::CurrentMeasure() const 
{ 
	return score.Part(partNum).Key(keyNum).Measure(measureNum);
}

