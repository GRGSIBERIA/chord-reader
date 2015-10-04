#pragma once
#include "ConstructionBase.hpp"
#include "Measure.hpp"

namespace score
{
	namespace score
	{
		class Key : public ConstructionBase < Key, Measure >
		{
			const std::wstring key;

		public:
			Key(const std::wstring& key) : key(key) {}

			const std::wstring& KeyString() const { return key;	}

			static _PPtr Instantiate(const std::wstring& key) { return _PPtr(new Key(key)); }

			const Measure& Measure(const size_t i) const { return *elem[i]; }
		};
	}
}