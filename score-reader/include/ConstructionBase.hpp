#pragma once
#include <vector>
#include <memory>

namespace score
{
	namespace score
	{
		template <class P, class T>
		class ConstructionBase : protected std::vector < std::shared_ptr< T > >
		{
		public:
			typedef std::shared_ptr<P> _PPtr;
			typedef std::shared_ptr<T> _TPtr;

			const size_t Size() const { return size(); }

			const _TPtr& At(const size_t i) const { return at(i); }

			static _TPtr Create() { return _TPtr(new T()); }

			static _PPtr Instantiate() { return _PPtr(new P()); }

			void PushBack(const _TPtr& ptr) { push_back(ptr); }
		};
	}
}