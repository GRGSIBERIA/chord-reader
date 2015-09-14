#pragma once
#include <vector>
#include <string>
#include <array>

#include "Chord.hpp"

namespace score
{
	namespace scale
	{
		/**
		* スケールの基底クラス
		*/
		class ScaleBase
		{
			const std::vector<int> scale;
			const std::wstring name;

		public:
			ScaleBase(const std::vector<int>& scale, const std::wstring& name) : scale(scale), name(name) {}

			const int Scale(const size_t& i) const { return scale[i]; }
			const std::wstring& Name() const { return name; }
		};

		/**
		* モードスケールの基底クラス
		*/
		class Mode : public ScaleBase
		{
			const int scaleNumber;

		public:
			Mode(const std::vector<int>& scale, const std::wstring& name, const int num) : ScaleBase(scale, name), scaleNumber(num) {}

			// 0から始まるモードスケールのインターバルの番号を返す
			const int ScaleNumber() const { return scaleNumber; }
		};

#define DEFINE_MODE(CLASS_NAME, NUM, C, D, E, F, G, A, B) \
		class CLASS_NAME : public Mode\
		{\
		public:\
			CLASS_NAME() : Mode({C, D, E, F, G, A, B}, L"CLASS_NAME", NUM) {}\
		}

		DEFINE_MODE(Ionian, 0, 0, 2, 4, 5, 7, 9, 11);
		DEFINE_MODE(Dorian, 1, 0, 2, 3, 5, 7, 9, 10);
		DEFINE_MODE(Phrygian, 2, 0, 1, 3, 5, 7, 8, 10);
		DEFINE_MODE(Lydian, 3, 0, 2, 4, 6, 7, 9, 11);
		DEFINE_MODE(Mixolydian, 4, 0, 2, 4, 5, 7, 9, 10);
		DEFINE_MODE(Aeolian, 5, 0, 2, 3, 5, 7, 8, 10);
		DEFINE_MODE(Locrian, 6, 0, 1, 3, 5, 6, 8, 10);

#define DEFINE_SCALE7(CLASS_NAME, C, D, E, F, G, A, B) \
		class CLASS_NAME : public ScaleBase\
		{\
		public:\
			CLASS_NAME() : ScaleBase({C, D, E, F, G, A, B}, L"CLASS_NAME") {}\
		}

#define DEFINE_SCALE5(CLASS_NAME, X1, X2, X3, X4, X5) \
		class CLASS_NAME : public ScaleBase\
		{\
		public:\
			CLASS_NAME() : ScaleBase({C, D, E, F, G, A, B}, L"CLASS_NAME") {}\
		}

		DEFINE_SCALE7(Major, 0, 2, 4, 5, 7, 9, 11);
		DEFINE_SCALE7(HarmonicMinor, 0, 2, 3, 5, 7, 8, 11);
		DEFINE_SCALE7(MelodicMinor, 0, 2, 3, 5, 7, 9, 11);
		DEFINE_SCALE7(NaturalMinor, 0, 2, 3, 5, 7, 8, 10);

		
		class ModeDatabase
		{
			typedef std::vector<Mode> Modes;

			const Modes modes = Modes{ {
				Ionian(),
				Dorian(),
				Phrygian(),
				Lydian(),
				Mixolydian(),
				Aeolian(),
				Locrian()
					} };

		public:
			static const Mode& Find(const std::vector<chord::Chord>& chords);
		};
	}
}