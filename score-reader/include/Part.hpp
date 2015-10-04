#pragma once
#include "ConstructionBase.hpp"
#include "ChordFactory.hpp"
#include "Key.hpp"

namespace score
{
	namespace score
	{
		class Part : public ConstructionBase<Part, Key>
		{
			const std::wstring name;

		public:
			Part(const std::wstring& name) : name(name) {}

			const std::wstring& Name() const { return name; }

			static _PPtr Instantiate(const std::wstring& name) { return _PPtr(new Part(name)); }
		};
	}
}