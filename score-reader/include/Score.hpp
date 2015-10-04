#pragma once
#include "Part.hpp"
#include "ConstructionBase.hpp"

namespace score
{
	namespace score
	{
		class Score : public ConstructionBase<Score, Part>
		{
			const std::wstring title;
			const std::wstring key;

		public:
			Score(const std::wstring& title, const std::wstring& key) : title(title), key(key) {}

			static _PPtr Instantiate(const std::wstring& title, const std::wstring& key) { return _PPtr(new Score(title, key)); }

			const std::wstring& Title() const { return title; }
			const std::wstring& Key() const { return key; }

			const Part& Part(const size_t i) const { return *elem[i]; }
		};
	}
}