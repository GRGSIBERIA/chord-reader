#pragma once
#include "Modal.hpp"

namespace score
{
	namespace scale
	{
		class Key
		{
		public:
			static const std::wstring Parallel(const std::wstring& str);	// ���咲(I)
			static const std::wstring Relative(const std::wstring& str);	// ���s��(maj=VIm, min=III)

			static const std::wstring Dominant(const std::wstring& str);		// ����(V)
			static const std::wstring MinorDominant(const std::wstring& str);	// ����2(maj=IIIm, min=VII)

			static const std::wstring SubDominant(const std::wstring& str);			// ������(IV)
			static const std::wstring MinorSubDominant(const std::wstring& str);	// ������2(maj=IIm, min=VI)
		};
	}
}