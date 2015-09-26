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
		typedef std::vector<int> ModalIndices;

		class KeyChordModalizer
		{
			const ModeTheory& mode;

			const Modal key;

		public:
			KeyChordModalizer(const Modal& key, const ModeTheory& mode);

			const ModalIndices GetPrimaryMode(const std::wstring& chordStr) const;
			//const ModeScale& GetAvailableMode(const std::wstring& chordStr);
		};
	}
}