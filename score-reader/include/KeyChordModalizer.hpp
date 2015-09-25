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

			const Modal key;

		public:
			KeyChordModalizer(const Modal& key, const bool isMajor = true);

			const ModeScale& GetPrimaryMode(const std::wstring& chordStr) const;
			const ModeScale& GetAvailableMode(const std::wstring& chordStr) const;
		};
	}
}