#pragma once
#include "Score.hpp"
#include "ScaleManager.hpp"

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

			const ScaleManager manager;

		public:
			ScoreTurner(const Score::_PPtr& score, const int rythm);
		};
	}
}