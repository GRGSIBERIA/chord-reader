#pragma once
#include <vector>

namespace score
{
	namespace scale
	{
		class ScaleBase
		{
			const std::vector<int> scale;

		public:
			ScaleBase(const std::vector<int>& scale) : scale(scale) {}
		};

#define DEFINE_SCALE(CLASS_NAME, C, D, E, F, G, A, B) \
		class CLASS_NAME : public ScaleBase\
		{\
		public:\
			CLASS_NAME() : ScaleBase({C, D, E, F, G, A, B}) {}\
		}

		DEFINE_SCALE(Ionian, 0, 2, 4, 5, 7, 9, 11);
		DEFINE_SCALE(Dorian, 0, 2, 3, 5, 7, 9, 10);
		DEFINE_SCALE(Phrygian, 0, 1, 3, 5, 7, 8, 10);
		DEFINE_SCALE(Lydian, 0, 2, 4, 6, 7, 9, 11);
		DEFINE_SCALE(Mixolydian, 0, 2, 4, 5, 7, 9, 10);
		DEFINE_SCALE(Aeolian, 0, 2, 3, 5, 7, 8, 10);
		DEFINE_SCALE(Locrian, 0, 1, 3, 5, 6, 8, 10);
	}
}