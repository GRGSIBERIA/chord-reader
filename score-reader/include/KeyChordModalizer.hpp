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
		typedef std::vector<int> ModeModals;
		typedef std::vector<ModeModalScale> ModeModalScales;

		class KeyChordModalizer
		{
			static const ScaleTheory stheory;

			const ModeTheory mtheory;

			const Scale scale;

			const Modal key;

			ModeModalScales modeScale;

		public:
			KeyChordModalizer(const Modal& key);
		};
	}
}