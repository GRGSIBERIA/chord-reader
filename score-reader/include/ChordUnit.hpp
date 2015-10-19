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
		// �X�R�A��̃R�[�h�N���X
		class ChordUnit
		{
			const std::wstring part;
			const std::wstring key;
			const chord::ChordPtr chordPtr;
			//const scale::ChordScale& chordScale;
			const int count;

		public:
			ChordUnit(const std::wstring& part, const std::wstring& key, const std::wstring& chordName, const int count)
				: key(key), chordPtr(chord::ChordFactory::CreateChord(chordName)), count(count), part(part)
			{
				
			}

			const chord::Chord& _GetChord() const { return *chordPtr; }

			GET_PROPERTY(const std::wstring&, Key, key);
			GET_PROPERTY(const std::wstring&, Part, part);
			GET_PROPERTY(const int, Count, count);
			__declspec(property(get = _GetChord)) const chord::Chord& Chord;
		};

		// ��p�̔z��N���X
		class ChordUnitArray : public std::vector < ChordUnit >
		{
		public:
			typedef ChordUnitArray::const_iterator Itr;

			ChordUnitArray() { reserve(64); }

			// ���̃p�[�g�̈ʒu��Ԃ�
			Itr NextPart(Itr& now) const
			{
				return std::find_if(now, end(), [now](const ChordUnit& b) { return now->Part != b.Part; });
			}

			// ���̃L�[�̈ʒu��Ԃ�
			Itr NextKey(Itr& now) const
			{
				return std::find_if(now, end(), [now](const ChordUnit& b) { return now->Key != b.Key; });
			}
		};
	}
}