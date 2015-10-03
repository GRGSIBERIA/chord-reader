#pragma once
#include "ConstructionBase.hpp"
#include "Measure.hpp"

namespace score
{
	namespace score
	{
		class Key : ConstructionBase < Key, Measure >
		{
			const std::wstring key;

		public:
			Key(const std::wstring& key) : key(key) {}

			const std::wstring& KeyString() const { return key;	}
		};
	}
}