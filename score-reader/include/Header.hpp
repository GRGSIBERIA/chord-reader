#pragma once
#include <string>
#include <memory>

namespace score
{
	namespace score
	{
		class Header
		{
			const std::wstring title;
			const std::wstring key;
			const int beat;
			const int note;

		public:
			Header(const std::wstring& title, const std::wstring& key, const int beat, const int note)
				: title(title), key(key), beat(beat), note(note) {}

			const std::wstring& _GetTitle() const { return title; }
			const std::wstring& _GetKey() const { return key; }
			const int _GetBeat() const { return beat; }
			const int _GetNote() const { return note; }

			__declspec(property(get = _GetTitle)) const std::wstring& Title;
			__declspec(property(get = _GetKey)) const std::wstring& Key;
			__declspec(property(get = _GetBeat)) const int Beat;
			__declspec(property(get = _GetNote)) const int Note;
		};
		typedef std::shared_ptr<Header> HeaderPtr;
	}
}