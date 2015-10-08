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

			GET_PROPERTY(const std::wstring&, Title);
			GET_PROPERTY(const std::wstring&, Key);
			GET_PROPERTY(const int, Beat);
			GET_PROPERTY(const int, Note);
		};
		typedef std::shared_ptr<Header> HeaderPtr;
	}
}