#pragma once
#include <string>
#include <vector>
#include <xml\tinyxml2.h>
#include "ChordUnit.hpp"
#include "Header.hpp"

namespace score
{
	namespace score
	{
		// XMLからコードを読み込んで，Chordインスタンスの配列を作る
		class ChordScore
		{
			ChordUnitArray chords;
			HeaderPtr header;

			void CollectHeader(const tinyxml2::XMLElement* header);
			void CollectScore(const tinyxml2::XMLElement* score);

		public:
			ChordScore(const std::string& path);

			const Header& _GetHeader() const { return *header; }
			const ChordUnitArray& _GetChords() const { return chords; }

			__declspec(property(get = _GetHeader)) const Header& Header;
			__declspec(property(get = _GetChords)) const ChordUnitArray& Chords;
		};
	}
}