#pragma once
#include <string>
#include <memory>
#include "Property.hpp"

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

			GET_PROPERTY(const std::wstring&, Title, title);
			GET_PROPERTY(const std::wstring&, Key, key);
			GET_PROPERTY(const int, Beat, beat);
			GET_PROPERTY(const int, Note, note);
		};
		typedef std::shared_ptr<Header> HeaderPtr;
	}
}