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

		class ScaleGenerator
		{
		public:
			static const ScaleIntervalArrayPtr Generate(const ScaleIntervals& interval);
		};
	}
}