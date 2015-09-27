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
		typedef std::vector<ModeModals> ModeModalScales;
		typedef std::vector<ModeModalScales> ModesOnScale;

		class KeyChordModalizer
		{
			static const ScaleTheory stheory;

			const ModeTheory mtheory;

			const Scale scale;

			const Modal key;

			ModesOnScale modeScale;

			ModesOnScale availables;

			void CalcModeScalesOnRoot(const size_t root);
			void CalcAvailableScaleOnRoot(const size_t root);

		public:
			KeyChordModalizer(const Modal& key);

			const ModeModals& GetModeModals(const size_t root, const size_t mode_num) const { return modeScale[root][mode_num]; }

			const ModeModals& GetAvailableModals(const size_t root, const size_t mode_num) const { return availables[root][mode_num]; }
		};
	}
}