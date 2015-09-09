#pragma once

namespace ts
{
	namespace chord
	{
		// 調性
		enum class Tone
		{
			Major,	// メジャー
			Minor	// マイナー
		};

		// 第七度
		enum class Dominant
		{
			None,			// なし
			Seven,			// 7th
			MajorSeven,		// M7
			DiminishedSeven	// dim7
		};

		// 第五度
		enum class Fifth
		{
			Perfect,	// 完全5度
			Diminished,	// -5th
			Augumented	// +5th
		};

		// テンションノート
		enum class Tension
		{
			FlatNine,		// -9
			Nine,			//  9
			SharpNine,		// +9
			Eleven,			//  11
			SharpEleven,	// +11
			FlatThirteen,	// -13
			Thirteen,		//  13
		};
	}
}