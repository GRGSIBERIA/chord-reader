#pragma once
#include <string>
#include <vector>
#include <memory>

#include "ChordConstruction.hpp"

namespace score
{
	namespace chord
	{
		class ChordFactory;

		// コードのベースクラス
		class Chord
		{
			const std::wstring chordName;	// コード名
			const std::wstring chordTone; // コードトーン名

		public:
			friend ChordFactory;

			const Root& root;
			const Tone& tone;
			const Fifth& fifth;
			const Dominant& dominant;
			const Tension& tension;
			const OnChord& onchord;

			Chord(const std::wstring& chordName, const Root& root, const Tone& tone, const Fifth& fifth, const Dominant& dominant, const Tension& tension, const OnChord& onchord)
				: chordName(chordName), root(root), tone(tone), fifth(fifth), dominant(dominant), tension(tension), onchord(onchord), chordTone(tone.Name() + dominant.Name() + fifth.Name()) {}

			Chord(const Chord& c)
				: chordName(c.chordName), root(c.root), tone(c.tone), fifth(c.fifth), dominant(c.dominant), tension(c.tension), onchord(c.onchord), chordTone(c.chordTone) {}

			const std::wstring& Name() const { return chordName; }
			const std::wstring& ChordTone() const { return chordTone; }
		};

		typedef std::shared_ptr<Chord> ChordPtr;
	}
}