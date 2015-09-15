#pragma once
#include "Chord.hpp"

namespace score
{
	namespace chord
	{
		class DiatonicDatabase
		{
			static std::shared_ptr<DiatonicDatabase> _ptr;
			DiatonicDatabase() {}
		public:
			static const DiatonicDatabase& GetInstance();
		};
	}
}