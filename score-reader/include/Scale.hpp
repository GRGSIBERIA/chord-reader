#pragma once
#include <vector>
#include <string>

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

		public:
			ScaleBase(const std::vector<int>& scale) : scale(scale) {}
			const int Scale(const size_t& i) const { return scale[i]; }
		};

		/**
		* モードスケールの基底クラス
		*/
		class Mode : public ScaleBase
		{
			const int scaleNumber;

		public:
			Mode(const std::vector<int>& scale, const int num) : ScaleBase(scale), scaleNumber(num) {}

			// 0から始まるインターバルの番号を返す
			const int ScaleNumber() const { return scaleNumber; }
		};

#define DEFINE_SCALE(CLASS_NAME, NUM, C, D, E, F, G, A, B) \
		class CLASS_NAME : public Mode\
		{\
			const std::wstring name;\
		public:\
			CLASS_NAME() : Mode({C, D, E, F, G, A, B}, NUM), name(L"CLASS_NAME") {}\
			const std::wstring& Name() const { return name; }\
		}

		DEFINE_SCALE(Ionian, 0, 0, 2, 4, 5, 7, 9, 11);
		DEFINE_SCALE(Dorian, 1, 0, 2, 3, 5, 7, 9, 10);
		DEFINE_SCALE(Phrygian, 2, 0, 1, 3, 5, 7, 8, 10);
		DEFINE_SCALE(Lydian, 3, 0, 2, 4, 6, 7, 9, 11);
		DEFINE_SCALE(Mixolydian, 4, 0, 2, 4, 5, 7, 9, 10);
		DEFINE_SCALE(Aeolian, 5, 0, 2, 3, 5, 7, 8, 10);
		DEFINE_SCALE(Locrian, 6, 0, 1, 3, 5, 6, 8, 10);
	}
}