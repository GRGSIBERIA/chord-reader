#pragma once
#include <vector>
#include <memory>

namespace score
{
	namespace score
	{
		template <class T>
		class ConstructionBase : protected std::vector < std::shared_ptr< T > >
		{
		public:
			typedef std::shared_ptr<T> _Ptr;


			//const _Ptr& operator[](size_t i) const { return at(i); operator[]}

			const size_t Size() const { return size(); }

			const _Ptr& At(const size_t i) const { return at(i); }

			static _Ptr Create() { return _Ptr(new T()); }

			void PushBack(const _Ptr& ptr) { push_back(ptr); }
		};
	}
}