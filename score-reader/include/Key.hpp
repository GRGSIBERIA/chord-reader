#pragma once
#include "Modal.hpp"

namespace score
{
	namespace scale
	{
		class Key
		{
		public:
			static const std::wstring Parallel(const std::wstring& str);	// “¯å’²(I)
			static const std::wstring Relative(const std::wstring& str);	// •½s’²(maj=VIm, min=III)

			static const std::wstring Dominant(const std::wstring& str);		// ‘®’²(V)
			static const std::wstring MinorDominant(const std::wstring& str);	// ‘®’²2(maj=IIIm, min=VII)

			static const std::wstring SubDominant(const std::wstring& str);			// ‰º‘®’²(IV)
			static const std::wstring MinorSubDominant(const std::wstring& str);	// ‰º‘®’²2(maj=IIm, min=VI)
		};
	}
}