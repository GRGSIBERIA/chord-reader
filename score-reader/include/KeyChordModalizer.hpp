#pragma once
#include "Modal.hpp"
#include "ModeTheory.hpp"

namespace score
{
	namespace scale
	{
		class KeyChordModalizer
		{
			ModeTheory mode;

		public:
			KeyChordModalizer(const Modal& key);

			
		};
	}
}