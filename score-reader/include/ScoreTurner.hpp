#pragma once
#include "Score.hpp"

namespace score
{
	namespace score
	{
		// •ˆ‚ß‚­‚èƒNƒ‰ƒX
		class ScoreTurner
		{
			const int rythm;	// ”q

			size_t partNum;
			size_t keyNum;
			size_t measureNum;
			size_t chordNum;
			int beat;

			const Score::_PPtr ptr;
			const Score& score;

		public:
			ScoreTurner(const Score::_PPtr& score, const int rythm) : rythm(rythm), partNum(0), keyNum(0), measureNum(0), chordNum(0), beat(0), ptr(score), score(*score) {}
		};
	}
}