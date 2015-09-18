#pragma once
#include <vector>
#include <string>
#include <array>

#include "Chord.hpp"

namespace score
{
	namespace scale
	{
		// �X�P�[�����̃C���^�[�o����\��
		typedef std::vector<int> ScaleIntervals;

		// ����X�P�[�����Q�Ƃ���Y���z��
		typedef std::vector<int> ScaleIndices;

		/**
		* �X�P�[���̊��N���X
		*/
		class ScaleBase
		{
			const ScaleIntervals scale;
			const std::wstring name;

		public:
			ScaleBase(const std::wstring& name, const ScaleIntervals& scale) : scale(scale), name(name) {}

			const int GetInterval(const size_t& i) const { return scale[i]; }
			const ScaleIntervals& Intervals() const { return scale; }
			const std::wstring& Name() const { return name; }
			const size_t Size() const { return scale.size(); }
		};

		class Scale : public ScaleBase
		{
		public:
			Scale(const std::wstring& name, const ScaleIntervals& scale) : ScaleBase(name, scale) {}
		};

		/**
		* ������������郂�[�h�X�P�[���N���X
		*/
		class ModeScale : public Scale
		{
			const ScaleIndices chordTones;
			const ScaleIndices avoidNotes;
			const ScaleIndices tritones;

		public:
			ModeScale(const std::wstring& name, const ScaleIntervals& scale, const ScaleIndices& chordTones, const ScaleIndices& avoidNotes, const ScaleIndices& tritones)
				: Scale(name, scale), chordTones(chordTones), avoidNotes(avoidNotes), tritones(tritones) {}
		};

		/**
		* ���[�h�X�P�[���̊��N���X
		*/
		class Mode : public ScaleBase
		{
			const int modeNumber;
			const std::vector<int> avoids;		// �A�{�C�h�m�[�g
			const std::vector<int> cares;		// �A�{�C�h -> �P�A�ɂł���x��
			const std::vector<int> tensions;	// �e���V�����m�[�g

		public:
			Mode(const std::wstring& name, const int modenum, const std::vector<int>& scale, const std::vector<int>& avoids, const std::vector<int>& cares, const std::vector<int>& tensions) 
				: ScaleBase(name, scale), avoids(avoids), modeNumber(modenum), cares(cares), tensions(tensions) {}

			// 0����n�܂郂�[�h�X�P�[���̃C���^�[�o���̔ԍ���Ԃ�
			const int ModeNumber() const { return modeNumber; }
		};

		
	}
}