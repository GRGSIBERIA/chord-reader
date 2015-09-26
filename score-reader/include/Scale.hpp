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
		protected:
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
			const ScaleIndices availableScale;

		public:
			ModeScale(const std::wstring& name, const ScaleIntervals& scale, const ScaleIndices& chordTones, const ScaleIndices& avoidNotes, const ScaleIndices& tritones, const ScaleIndices& availables)
				: Scale(name, scale), chordTones(chordTones), avoidNotes(avoidNotes), tritones(tritones), availableScale(availables) {}

			const ScaleIndices& GetAvoids() const { return avoidNotes; }
			const ScaleIndices& GetTritones() const { return tritones; }
			const ScaleIndices& GetAvailableScale() const { return availableScale; }
		};
	}
}