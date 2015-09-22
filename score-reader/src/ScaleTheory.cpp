#include "ScaleTheory.hpp"
#include <algorithm>
using namespace score::scale;

void ScaleTheory::BuildScale(const size_t i)
{
	auto& scale = intervalArray[i];

	for (size_t j = 0; j < modalsInScale; ++j)
	{
		scale[j] = intervalArray[0][j] + (int)i;
		if (scale[j] >= numberOfModal) scale[j] -= numberOfModal;
	}

	// 必要ないかもしれない
	//std::sort(scale.begin(), scale.end());	// 適当に数字を大きくしてからソートする
}

ScaleTheory::ScaleTheory(const ScaleIntervals& intervals) : intervalArray(numberOfModal, ScaleIntervals(intervals.size())), modalsInScale(intervals.size())
{
	intervalArray.resize(numberOfModal, ScaleIntervals(intervals.size()));
	intervalArray[0] = intervals;

	for (size_t i = 1; i < numberOfModal; ++i)
	{
		size_t tmp_i = i >= numberOfModal ? i - numberOfModal : i;
		BuildScale(tmp_i);
	}
}