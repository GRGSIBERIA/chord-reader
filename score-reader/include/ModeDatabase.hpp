#include "Scale.hpp"
#include <memory>
#include <array>

namespace score
{
	namespace scale
	{
		/**
		* モードスケール用のデータベース
		* シングルトンクラス
		*/
		class ModeDatabase
		{
			typedef std::array<Mode, 7> ModeArray;
			typedef std::array<std::wstring, 7> Alternatives;

			const ModeArray modes = ModeArray{ {
				Mode(L"Ionian",		0, { 0, 2, 4, 5, 7, 9, 11 }, { 5 },		{ 1 },		{ 2, 9 }),
				Mode(L"Dorian",		1, { 0, 2, 3, 5, 7, 9, 10 }, { 10 },	{ -1 },		{ 2, 5 }),
				Mode(L"Phrygian",	2, { 0, 1, 3, 5, 7, 8, 10 }, { 0, 5 },	{ 1, 1 },	{ 2, 5 }),
				Mode(L"Lydian",		3, { 0, 2, 4, 6, 7, 9, 11 }, {},		{},			{ 2, 6, 9 }),
				Mode(L"Mixolydian", 4, { 0, 2, 4, 5, 7, 9, 10 }, { 5 },		{ 1 },		{ 2, 9 }),
				Mode(L"Aeolian",	5, { 0, 2, 3, 5, 7, 8, 10 }, { 9 },		{ 1 },		{ 2, 5 }),
				Mode(L"Locrian",	6, { 0, 1, 3, 5, 6, 8, 10 }, { 0 },		{ 1 },		{ 5, 8 })
					} };

			const Alternatives alternatives = Alternatives{ {
				L"Lydian",
				L"Aeolian",
				L"Dorian",
				L"Lydian",
				L"Mixolydian",
				L"Dorian",
				L"Locrian"
					} };

			static std::shared_ptr<ModeDatabase> _ptr;
			ModeDatabase() {}

		public:
			const Mode& Modes(const std::wstring& name) const;
			const Mode& Modes(const size_t index) const;

			const Mode& FindAlter(const Mode& mode) const;				// 代替スケールの検索
			const Mode& FindAlter(const std::wstring& name) const;		// 代替スケールの検索

			static const ModeDatabase& GetInstance();
		};
	}
}