#pragma once
#include <string>
#include <vector>
#include "Chord.hpp"
#include "ChordFactory.hpp"

namespace score
{
	namespace score
	{
		// �X�R�A��̃R�[�h�N���X
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

		// ��p�̔z��N���X
		class ChordUnitArray : public std::vector < ChordUnit >
		{
		public:
			ChordUnitArray() { reserve(128); }
		};
	}
}