#pragma once
#include <vector>
#include <string>
#include <array>

#include "Chord.hpp"

namespace score
{
	namespace scale
	{
		// スケール内のインターバルを表す
		typedef std::vector<int> ScaleIntervals;

		// あるスケールを参照する添字配列
		typedef std::vector<int> ScaleIndices;

		/**
		* スケールの基底クラス
		*/
		class ScaleBase
		{
			const ScaleIntervals scale;
			const std::wstring name;

		public:
			ScaleBase(const std::wstring& name, const ScaleIntervals& scale) : scale(scale), name(name) {}

			const int GetInterval(const size_t& i) const { return scale[i]; }
			const ScaleIntervals& Intervals() const { return scale; }
			const std::wstring& Name() const { return name; }
			const size_t Size() const { return scale.size(); }
		};

		class Scale : public ScaleBase
		{
		public:
			Scale(const std::wstring& name, const ScaleIntervals& scale) : ScaleBase(name, scale) {}
		};

		/**
		* 自動生成されるモードスケールクラス
		*/
		class ModeScale : public Scale
		{
			const ScaleIndices chordTones;
			const ScaleIndices avoidNotes;
			const ScaleIndices tritones;

		public:
			ModeScale(const std::wstring& name, const ScaleIntervals& scale, const ScaleIndices& chordTones, const ScaleIndices& avoidNotes, const ScaleIndices& tritones)
				: Scale(name, scale), chordTones(chordTones), avoidNotes(avoidNotes), tritones(tritones) {}
		};

		/**
		* モードスケールの基底クラス
		*/
		class Mode : public ScaleBase
		{
			const int modeNumber;
			const std::vector<int> avoids;		// アボイドノート
			const std::vector<int> cares;		// アボイド -> ケアにできる度数
			const std::vector<int> tensions;	// テンションノート

		public:
			Mode(const std::wstring& name, const int modenum, const std::vector<int>& scale, const std::vector<int>& avoids, const std::vector<int>& cares, const std::vector<int>& tensions) 
				: ScaleBase(name, scale), avoids(avoids), modeNumber(modenum), cares(cares), tensions(tensions) {}

			// 0から始まるモードスケールのインターバルの番号を返す
			const int ModeNumber() const { return modeNumber; }
		};

		
	}
}