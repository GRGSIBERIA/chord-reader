#pragma once
#include "Chord.hpp"
#include "ChordFactory.hpp"

namespace score
{
	namespace chord
	{
		/**
		* ダイアトニックコードを検索するためのクラス
		*/
		class DiatonicDatabase
		{
			typedef std::array<ChordPtr, 7> Diatonics;
			const Diatonics major_diatonic = Diatonics{ {
				ChordFactory::CreateChord(L"CM7"),
				ChordFactory::CreateChord(L"Dm7"),
				ChordFactory::CreateChord(L"Em7"),
				ChordFactory::CreateChord(L"FM7"),
				ChordFactory::CreateChord(L"G7"),
				ChordFactory::CreateChord(L"Am7"),
				ChordFactory::CreateChord(L"Bm7-5")
					} };

			static std::shared_ptr<DiatonicDatabase> _ptr;
			DiatonicDatabase() {}
		public:
			static const DiatonicDatabase& GetInstance();
		};
	}
}