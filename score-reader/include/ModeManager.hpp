#pragma once
#include "KeyChordModalizer.hpp"

namespace score
{
	namespace score
	{
		class ModeManager : public std::vector<scale::KeyChordModalizer>
		{
		public:
			// �L�[����ǉ�
			void PushBack(const std::wstring& key) { 
				if (std::find_if(begin(), end(), [key](const scale::KeyChordModalizer& m) { return key == m.KeyName(); }) == end())
					emplace_back(key);
			}
			
			// �L�[����T��
			const scale::KeyChordModalizer& Find(const std::wstring& key) const { 
				return *std::find_if(begin(), end(), [key](const scale::KeyChordModalizer& m) { return key == m.KeyName(); }); 
			}
		};
	}
}