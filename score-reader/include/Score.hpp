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
			const int beat;
			const int note;

		public:
			Score(const std::wstring& title, const std::wstring& key, const int note, const int beat) : title(title), key(key), note(note), beat(beat) {}

			static _PPtr Instantiate(const std::wstring& title, const std::wstring& key, const int note, const int beat) { return _PPtr(new Score(title, key, note, beat)); }

			const std::wstring& Title() const { return title; }
			const std::wstring& Key() const { return key; }
			const int Beat() const { return beat; }		// ”q
			const int Note() const { return note; }		// ‰¹•„‚Ìí—Ş

			const Part& Part(const size_t i) const { return *elem[i]; }
		};
	}
}