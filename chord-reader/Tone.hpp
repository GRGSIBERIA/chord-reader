#pragma once
#include <string>

namespace cr
{
	namespace chord
	{
		class Tone
		{
			std::wstring tone;

		public:
			Tone(const std::wstring& tone)
				: tone(tone) {}

			Tone() : tone() {}
		};

		class Major : public Tone
		{
		public:
			Major() : Tone(L"") {}
		};

		class Minor : public Tone
		{
		public:
			Minor() : Tone(L"m") {}
		};
	}
}