#pragma once
#include "Chord.hpp"
#include "ConstructionBase.hpp"
#include "ChordFactory.hpp"

namespace score
{
	namespace score
	{
		class Beat : public ConstructionBase < chord::Chord >
		{
			int time;
		public:
			Beat(const int time) : time(time) {}

			const int Time() const { return time; }

			void PushBack(const std::wstring& chordStr) { push_back(chord::ChordFactory::CreateChord(chordStr)); }
			void PushBack(const _Ptr& ptr) = delete;
		};
	}
}