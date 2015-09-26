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
		* �X�P�[�����_�N���X
		*/
		class ScaleTheory
		{
			ScaleIntervalArray intervalArray;
			const size_t numberOfModal = 12;	// 12���K
			const size_t modalsInScale;			// �X�P�[�����̉��K��

			void BuildScale(const size_t i);

		public:
			/**
			* ���̓C���^�[�o������C���ꂼ��̃C���^�[�o�����C�X�P�[����������������
			*/
			ScaleTheory(const ScaleIntervals& intervals);

			const size_t NumberOfModal() const { return numberOfModal; }
			const ScaleIntervals& GetScale(const size_t modal) const { return intervalArray[modal]; }
			const ScaleIntervals& GetScale(const Modal modal) const { return intervalArray[(size_t)modal]; }
		};
	}
}