#pragma once
#include <string>
#include <array>

namespace score
{
	namespace scale
	{
		// ‰¹ŠK‚Ì’è”
		enum class Modal
		{
			C = 0,
			CSharp = 1,
			DFlat = 1,
			D = 2,
			DSharp = 3,
			EFlat = 3,
			E = 4,
			F = 5,
			FSharp = 6,
			GFlat = 6,
			G = 7,
			GSharp = 8,
			AFlat = 8,
			A = 9,
			ASharp = 10,
			BFlat = 10,
			B = 11
		};

		// ’è”‚Æ”’l‚Ì‘ŠŒİ•ÏŠ·
		class Modalize
		{
			static const std::array<std::wstring, 12> sharp;
			static const std::array<std::wstring, 12> flat;

		public:
			static Modal ToModal(const int& modal);
			static Modal ToModal(const std::wstring& str);
			static int ToInt(const Modal& modal);
			static int ToInt(const std::wstring& str);
			static const std::wstring& ToString(const Modal& modal, const bool isSharp=true);
			static const std::wstring& ToString(const int& modal, const bool isSharp=true);
			static bool HasMinor(const std::wstring& str);
		};
	}
}