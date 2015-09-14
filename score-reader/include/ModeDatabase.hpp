#include "Scale.hpp"

namespace score
{
	namespace scale
	{
		class ModeDatabase
		{
			typedef std::vector<Mode> Modes;

			const Modes modes = Modes{ {
				Mode(L"Ionian", 0, { 0, 2, 4, 5, 7, 9, 11 }, { 5 }),
				Mode(L"Dorian", 1, { 0, 2, 3, 5, 7, 9, 10 }, { 9 }),
				Mode(L"Phrygian", 2, { 0, 1, 3, 5, 7, 8, 10 }, { 1, 8 }),
				Mode(L"Lydian", 3, { 0, 2, 4, 6, 7, 9, 11 }, {}),
				Mode(L"Mixolydian", 4, { 0, 2, 4, 5, 7, 9, 10 }, { 5 }),
				Mode(L"Aeolian", 5, { 0, 2, 3, 5, 7, 8, 10 }, { 9 }),
				Mode(L"Locrian", 6, { 0, 1, 3, 5, 6, 8, 10 }, { 1, 8 })
					} };

		public:
			static const Mode& Find(const int key, const bool isMajor, const std::vector<chord::Chord>& chords);
		};
	}
}