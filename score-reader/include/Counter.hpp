#pragma once

namespace score
{
	namespace score
	{
		class Counter
		{
			const int rythm;	// îèéq

		public:
			size_t partNum;
			size_t keyNum;
			size_t measureNum;
			size_t chordNum;
			int beat;

			Counter(const int rythm) : rythm(rythm), partNum(0), keyNum(0), measureNum(0), chordNum(0), beat(0) {}

			void Increment()
			{
				beat++;
				if (rythm <= beat)
					beat = 0;
			}
		};
	}
}