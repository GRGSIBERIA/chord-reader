#pragma once
#include <vector>
#include <string>
#include <array>

#include "Chord.hpp"

namespace score
{
	namespace scale
	{
		/**
		* �X�P�[���̊��N���X
		*/
		class ScaleBase
		{
			const std::vector<int> scale;
			const std::wstring name;

		public:
			ScaleBase(const std::wstring& name, const std::vector<int>& scale) : scale(scale), name(name) {}

			const int Scale(const size_t& i) const { return scale[i]; }
			const std::wstring& Name() const { return name; }
		};

		/**
		* ���[�h�X�P�[���̊��N���X
		*/
		class Mode : public ScaleBase
		{
			const int modeNumber;
			const std::vector<int> avoids;	// �A�{�C�h�m�[�g

		public:
			Mode(const std::wstring& name, const int num, const std::vector<int>& scale, const std::vector<int>& avoids) 
				: ScaleBase(name, scale), avoids(avoids), modeNumber(num) {}

			// 0����n�܂郂�[�h�X�P�[���̃C���^�[�o���̔ԍ���Ԃ�
			const int ModeNumber() const { return modeNumber; }
		};

		
	}
}