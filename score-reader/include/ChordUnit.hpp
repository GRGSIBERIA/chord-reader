#pragma once
#include <string>
#include "Chord.hpp"
#include "ChordFactory.hpp"

namespace score
{
	namespace score
	{
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

			const chord::Chord& Chord() const { return *chordPtr; }
			const std::wstring& Key() const { return key; }
			const int Count() const { return count; }
			const std::wstring& Part() const { return part; }
		};
	}
}