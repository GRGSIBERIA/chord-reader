#pragma once
#include <string>
#include <vector>
#include "Chord.hpp"
#include "ChordFactory.hpp"
#include "Property.hpp"
#include "ScaleDatabase.hpp"

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
			const scale::KeyChordModalizer& modalizer;
			const int count;

			int scaleIndex;

		public:
			ChordUnit(const std::wstring& part, const std::wstring& key, const std::wstring& chordName, const int count);

			const chord::Chord& _GetChord() const { return *chordPtr; }

			GET_PROPERTY(const std::wstring&, Key, key);
			GET_PROPERTY(const std::wstring&, Part, part);
			GET_PROPERTY(const int, Count, count);
			GET_PROPERTY(const int, ModeIndex, scaleIndex);
			__declspec(property(get = _GetChord)) const chord::Chord& Chord;

			const scale::ModeModals Scale(const size_t modeIndex) const;
			const scale::ModeModals Scale() const;
			const scale::ModeModals Available(const size_t modeIndex) const;
			const scale::ModeModals Available() const;
			const scale::ModeModals Usable(const size_t modeIndex) const;
			const scale::ModeModals Usable() const;
		};

		// ��p�̔z��N���X
		class ChordUnitArray : public std::vector < ChordUnit >
		{
		public:
			typedef const ChordUnitArray::const_iterator Itr;

			ChordUnitArray() { reserve(64); }

			Itr NextPart(Itr& now) const;	// ���̃p�[�g�̈ʒu��Ԃ�
			Itr NextKey(Itr& now) const;	// ���̃L�[�̈ʒu��Ԃ�
		};
	}
}