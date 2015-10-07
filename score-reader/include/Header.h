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
		};
		typedef std::shared_ptr<Header> HeaderPtr;
	}
}