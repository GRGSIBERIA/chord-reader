#pragma once
#include "Modal.hpp"

namespace score
{
	namespace scale
	{
		// •¶š—ñ‚ğ“]’²‚³‚¹‚é
		class Modulation
		{
		public:
			static const std::wstring Parallel(const std::wstring& key);	// “¯å’²(I)
			static const std::wstring Relative(const std::wstring& key);	// •½s’²(maj=VIm, min=III)
			static const std::wstring Dominant(const std::wstring& key);		// ‘®’²(V)
			static const std::wstring SubDominant(const std::wstring& key);			// ‰º‘®’²(IV)
			static const std::wstring MinorDominant(const std::wstring& key);	// ‘®’²2(maj=IIIm, min=VII)
			static const std::wstring MinorSubDominant(const std::wstring& key);	// ‰º‘®’²2(maj=IIm, min=VI)
		};
	}
}