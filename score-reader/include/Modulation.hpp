#pragma once
#include "Modal.hpp"

namespace score
{
	namespace scale
	{
		// 文字列を転調させる
		class Modulation
		{
		public:
			static const std::wstring Parallel(const std::wstring& str);	// 同主調(I)
			static const std::wstring Relative(const std::wstring& str);	// 平行調(maj=VIm, min=III)

			static const std::wstring Dominant(const std::wstring& str);		// 属調(V)
			static const std::wstring MinorDominant(const std::wstring& str);	// 属調2(maj=IIIm, min=VII)

			static const std::wstring SubDominant(const std::wstring& str);			// 下属調(IV)
			static const std::wstring MinorSubDominant(const std::wstring& str);	// 下属調2(maj=IIm, min=VI)
		};
	}
}