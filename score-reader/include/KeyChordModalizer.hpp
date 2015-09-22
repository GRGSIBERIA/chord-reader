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

			typedef std::array<int, 7> Intervals;
			typedef std::array<Intervals, 7> ScaleArray;

			ScaleArray scales;
			Modal key;

		public:
			KeyChordModalizer(const Modal& key, const bool isMajor = true);

			const Intervals& GetPrimaryMode(const Modal& root) { return scales[(int)root - (int)key]; }
		};
	}
}