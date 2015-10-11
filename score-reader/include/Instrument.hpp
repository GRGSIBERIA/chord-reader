#pragma once
#include <vector>
#include "String.hpp"

namespace score
{
	namespace inst
	{
		// 楽器クラス
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

			// 弦とフレット数からMIDIノート番号を返す
			const MidiNoteNumber MidiNum(const int stringNum, const int fretNum) const { return strings[stringNum].Tuning + fretNum; }

			// フレット番号を返す，マイナスの場合は存在しない
			const int FretNum(const int stringNum, const MidiNoteNumber midiNoteNum) const { return midiNoteNum - strings[stringNum].Tuning; }
		};
	}
}