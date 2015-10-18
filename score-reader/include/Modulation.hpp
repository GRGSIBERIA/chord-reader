#pragma once
#include "Modal.hpp"

namespace score
{
	namespace scale
	{
		enum class RelatedKey
		{
			Parallel,			// 同主調
			Relative,			// 平行調
			Dominant,			// 属調
			Subdominant,		// 下属調
			MinorDominant,		// 反転属調
			MinorSubdominant	// 反転下属調
		};

		// 未定義のRelatedKeyが投げられた場合の例外
		class UndefinedRelatedKeyException : public std::exception
		{
		public:
			UndefinedRelatedKeyException() : exception("なんかよーわからん") {}
		};

		// 文字列を転調させる
		class Modulation
		{
		public:
			static const std::wstring Modulate(const RelatedKey relate, const std::wstring& key);
			static const std::wstring Parallel(const std::wstring& key);			// 同主調(I)
			static const std::wstring Relative(const std::wstring& key);			// 平行調(maj=VIm, min=III)
			static const std::wstring Dominant(const std::wstring& key);			// 属調(V)
			static const std::wstring SubDominant(const std::wstring& key);			// 下属調(IV)
			static const std::wstring MinorDominant(const std::wstring& key);		// 属調2(maj=IIIm, min=VII)
			static const std::wstring MinorSubDominant(const std::wstring& key);	// 下属調2(maj=IIm, min=VI)
		};
	}
}