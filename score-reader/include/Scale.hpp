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

#define DEFINE_SCALE(CLASS_NAME, PARAM) \
		class CLASS_NAME : public ScaleBase\
		{\
		public:\
			CLASS_NAME() : ScaleBase(PARAM) {}\
		};

		DEFINE_SCALE(Ionian, {});
	}
}