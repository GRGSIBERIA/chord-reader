#pragma once
#include <vector>
#include <memory>

namespace score
{
	namespace scale
	{
		typedef std::vector<int> ScaleIntervals;
		typedef std::vector<ScaleIntervals> ScaleIntervalArray;
		typedef std::shared_ptr<ScaleIntervalArray> ScaleIntervalArrayPtr;

		class ScaleTheory
		{
			ScaleIntervalArray intervalArray;

		public:
			ScaleTheory(const ScaleIntervals& intervals);
		};
	}
}