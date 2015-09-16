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
			typedef std::array<const Chord&, 7> Diatonics;
			const Diatonics major_diatonic = Diatonics{ {
				ChordFactory::CreateChord(0, 4, 7, 11),		// IM7
				ChordFactory::CreateChord(0, 3, 7, 10),		// IIm7
				ChordFactory::CreateChord(0, 3, 7, 10),		// IIIm7
				ChordFactory::CreateChord(0, 4, 7, 11),		// IVM7
				ChordFactory::CreateChord(0, 4, 7),			// V7
				ChordFactory::CreateChord(0, 3, 7, 10),		// VIm7
				ChordFactory::CreateChord(0, 3, 6, 10),		// VIIm7-5
					} };

			static std::shared_ptr<DiatonicDatabase> _ptr;
			DiatonicDatabase() {}
		public:
			static const DiatonicDatabase& GetInstance();

			// 1度は0, 7度は6として，インデックスを指定
			const Chord& GetChord(const size_t index) const;
			const Chord& GetChord(const size_t index, const bool isMajor) const;
		};
	}
}