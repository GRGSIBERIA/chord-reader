#pragma once
#include "Modal.hpp"
#include "ScaleTheory.hpp"
#include "Scale.hpp"
#include "ModeTheory.hpp"
#include <array>

namespace score
{
	namespace scale
	{
		class KeyChordModalizer
		{
			const ModeTheory mode;

			typedef std::array<int, 7> _Scale;
			typedef std::array<_Scale, 7> ScaleArray;

			ScaleArray scales;

		public:
			KeyChordModalizer(const Modal& key, const bool isMajor = true);

			
		};
	}
}