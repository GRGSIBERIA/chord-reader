#pragma once
#include <vector>
#include <memory>

namespace score
{
	namespace score
	{
		template <class P, class T>
		class ConstructionBase
		{
		protected:
			std::vector < std::shared_ptr< T > > elem;

		public:
			typedef std::shared_ptr<P> _PPtr;
			typedef std::shared_ptr<T> _TPtr;

			static _TPtr Create() { return _TPtr(new T()); }

			static _PPtr Instantiate() { return _PPtr(new P()); }

			void PushBack(const _TPtr& ptr) { elem.push_back(ptr); }
		};
	}
}