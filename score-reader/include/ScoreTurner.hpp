#pragma once
#include "Score.hpp"
#include "ScaleManager.hpp"

namespace score
{
	namespace score
	{
		// ���߂���N���X
		class ScoreTurner
		{
			const int rythm;	// ���q

			size_t partNum;
			size_t keyNum;
			size_t measureNum;
			int count;
			bool endFlag;

			const Score::_PPtr ptr;
			const Score& score;

			const ScaleManager manager;

			void Initialize();

		public:
			ScoreTurner(const Score::_PPtr& score, const int rythm);

			bool Count();	// �J�E���g������āC���̏��߂ɔ�񂾂�true��Ԃ�

			const chord::Chord& CurrentChord() const;

			const Measure& CurrentMeasure() const;

			const bool IsEnded() const;

			void Restart();
		};
	}
}