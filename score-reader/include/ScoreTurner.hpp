#pragma once
#include "Score.hpp"

namespace score
{
	namespace score
	{
		// 譜めくりクラス
		class ScoreTurner
		{
			const int rythm;	// 拍子

			size_t partNum;
			size_t keyNum;
			size_t measureNum;
			size_t chordNum;
			int beat;

			const Score::_PPtr ptr;
			const Score& score;

		public:
			ScoreTurner(const Score::_PPtr& score, const int rythm);
		};
	}
}