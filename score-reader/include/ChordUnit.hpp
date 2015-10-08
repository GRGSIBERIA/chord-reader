#pragma once
#include <string>
#include <vector>
#include "Chord.hpp"
#include "ChordFactory.hpp"
#include "Property.hpp"

namespace score
{
	namespace score
	{
		// スコア上のコードクラス
		class ChordUnit
		{
			const std::wstring part;
			const std::wstring key;
			const chord::ChordPtr chordPtr;
			const int count;

		public:
			ChordUnit(const std::wstring& part, const std::wstring& key, const std::wstring& chordName, const int count)
				: key(key), chordPtr(chord::ChordFactory::CreateChord(chordName)), count(count), part(part)
			{
				
			}

			const chord::Chord& _GetChord() const { return *chordPtr; }
			//const std::wstring& Key() const { return key; }
			//const int Count() const { return count; }
			//const std::wstring& Part() const { return part; }

			GET_PROPERTY(const std::wstring&, Key);
			GET_PROPERTY(const std::wstring&, Part);
			GET_PROPERTY(const int, Count);
			__declspec(property(get = _GetChord)) const chord::Chord& Chord;
		};

		// 専用の配列クラス
		class ChordUnitArray : public std::vector < ChordUnit >
		{
		public:
			typedef ChordUnitArray::const_iterator Itr;

			ChordUnitArray() { reserve(128); }

			// 次のパートの位置を返す
			Itr NextPart(const Itr& now) const
			{
				return std::find_if(now, end(), [now](Itr b) { return now->Part() == b->Part(); });
			}

			// 次のキーの位置を返す
			Itr NextKey(const Itr& now) const
			{
				return std::find_if(now, end(), [now](Itr b) { return now->Key() == b->Key(); });
			}
		};
	}
}