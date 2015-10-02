#pragma once
#include "ConstructionBase.hpp"
#include "ChordFactory.hpp"

namespace score
{
	namespace score
	{
		class Part : public ConstructionBase<chord::Chord>
		{
		public:
			void PushBack(const std::wstring& chordStr) { push_back(chord::ChordFactory::CreateChord(chordStr)); }
		};
	}
}