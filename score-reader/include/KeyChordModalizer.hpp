#pragma once
#include "Modal.hpp"
#include "ScaleTheory.hpp"
#include "ModeTheory.hpp"

namespace score
{
	namespace scale
	{
		class KeyChordModalizer
		{
			const ScaleTheory scale = ScaleTheory();
			const ModeTheory mode;

		public:
			KeyChordModalizer(const Modal& key, const bool isMajor = true);

			
		};
	}
}