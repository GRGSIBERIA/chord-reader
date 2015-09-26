#pragma once
#include <vector>
#include <memory>
#include "Modal.hpp"

namespace score
{
	namespace scale
	{
		typedef std::vector<int> ScaleIntervals;
		typedef std::vector<ScaleIntervals> ScaleIntervalArray;

		/**
		* スケール理論クラス
		*/
		class ScaleTheory
		{
			ScaleIntervalArray intervalArray;
			const size_t numberOfModal = 12;	// 12音階
			const size_t modalsInScale;			// スケール内の音階数

			void BuildScale(const size_t i);

		public:
			/**
			* 入力インターバルから，それぞれのインターバルより，スケールを自動生成する
			*/
			ScaleTheory(const ScaleIntervals& intervals);

			const size_t NumberOfModal() const { return numberOfModal; }
			const ScaleIntervals& GetScale(const size_t modal) const { return intervalArray[modal]; }
			const ScaleIntervals& GetScale(const Modal modal) const { return intervalArray[(size_t)modal]; }
		};
	}
}