#pragma once
#include <array>
#include "Modal.hpp"
#include "KeyChordModalizer.hpp"

namespace score
{
	namespace scale
	{
		class ScaleDatabase
		{
			static const std::array<KeyChordModalizer, 12> major;
			static const std::array<KeyChordModalizer, 12> minor;

		public:
			static const KeyChordModalizer& Find(const std::wstring& key);
			static const KeyChordModalizer& Find(const Modal modal, const bool isMajor);
			static const KeyChordModalizer& Find(const int modal, const bool isMajor);

			static const KeyChordModalizer& Major(const std::wstring& key);
			static const KeyChordModalizer& Minor(const std::wstring& key);

			static const KeyChordModalizer& Related(const std::wstring& key, const RelatedKey related);
			static const KeyChordModalizer& Parallel(const std::wstring& key);
			static const KeyChordModalizer& Relative(const std::wstring& key);
			static const KeyChordModalizer& Dominant(const std::wstring& key);
			static const KeyChordModalizer& Subdominant(const std::wstring& key);
			static const KeyChordModalizer& MinorDominant(const std::wstring& key);
			static const KeyChordModalizer& MinorSubdominant(const std::wstring& key);
		};
	}
}