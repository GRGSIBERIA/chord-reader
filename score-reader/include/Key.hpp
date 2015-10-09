#pragma once
#include "Modal.hpp"

namespace score
{
	namespace scale
	{
		class Key
		{
		public:
			static const std::wstring Parallel(const std::wstring& str);
			static const std::wstring Relative(const std::wstring& str);

			static const std::wstring Dominant(const std::wstring& str);
			static const std::wstring MinorDominant(const std::wstring& str);

			static const std::wstring SubDominant(const std::wstring& str);
			static const std::wstring MinorSubDominant(const std::wstring& str);
		};
	}
}