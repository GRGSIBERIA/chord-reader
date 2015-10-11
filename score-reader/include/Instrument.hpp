#pragma once
#include <vector>
#include "String.hpp"

namespace score
{
	namespace inst
	{
		// �y��N���X
		class Instrument
		{
			std::vector<String> strings;

		public:
			Instrument(const int frets, const std::vector<MidiNoteNumber>& tunings) {
				strings.reserve(tunings.size());
				for (const auto tuning : tunings)
					strings.emplace_back(tuning, frets);
			}

			GET_PROPERTY(const std::vector<String>&, Strings, strings);

			// ���ƃt���b�g������MIDI�m�[�g�ԍ���Ԃ�
			const MidiNoteNumber MidiNum(const int stringNum, const int fretNum) const { return strings[stringNum].Tuning + fretNum; }

			// �t���b�g�ԍ���Ԃ��C�}�C�i�X�̏ꍇ�͑��݂��Ȃ�
			const int FretNum(const int stringNum, const MidiNoteNumber midiNoteNum) const { return midiNoteNum - strings[stringNum].Tuning; }
		};
	}
}