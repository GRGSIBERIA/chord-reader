#pragma once
#include "Modal.hpp"
#include "ScaleTheory.hpp"
#include "Scale.hpp"
#include "ModeTheory.hpp"
#include "ChordScale.hpp"

namespace score
{
	namespace scale
	{
		// あるキーのモードスケールを管理するクラス
		class KeyChordModalizer
		{
			static const ScaleTheory majtheory;
			static const ScaleTheory mintheory;

			const ModeTheory mtheory;

			const Scale scale;

			const Modal key;

			const std::wstring keyName;

			ModesOnScale modeScale;

			ModesOnScale availables;

			void CalcModeScalesOnRoot(const size_t root);
			void CalcAvailableScaleOnRoot(const size_t root);

		public:
			KeyChordModalizer(const std::wstring& keyName, const Modal& key, const ScaleTheory& theory, const ScaleIndices& chordTone);
			KeyChordModalizer(const std::wstring& str);		// キーを指定する

			// モードを取得する
			const ModeModals& ModeScale(const size_t root, const size_t mode_num) const { return modeScale[root][mode_num]; }
			const ModeModals& ModeScale(const std::wstring& str, const size_t mode_num) const;

			// 現在のコードに対して主体的なモードを返す
			const ModeModals& PrimaryModeScale(const std::wstring& str) const;
			const ModeModals& PrimaryModeScale(const size_t rootIndex) const { return modeScale[rootIndex][rootIndex]; }

			// アベイラブルスケールを取得する
			const ModeModals& AvailableScale(const size_t root, const size_t mode_num) const { return availables[root][mode_num]; }
			const ModeModals& AvailableScale(const std::wstring& str, const size_t mode_num) const;

			// あるコードにおけるモードスケールの中で，アベイラブルスケールをすべて取得する
			const ModeModalScales& Availables(const std::wstring& chord) const;

			// 現在のコードに対して主体的なアベイラブルスケールを返す
			const ModeModals& PrimaryAvailableScale(const std::wstring& str) const;
			const ModeModals& PrimaryAvailableScale(const size_t rootIndex) const { return availables[rootIndex][rootIndex]; }

			// コードからモードインデックスを返す
			const int ModeIndex(const std::wstring& chord) const { return scale.GetIndex(chord); }

			GET_PROPERTY(const std::wstring&, KeyName, keyName);
			GET_PROPERTY(const DiatonicChords&, Diatonics, mtheory.Diatonics);

			const ChordScale Mode(const std::wstring& chord, const size_t mode_num) const;
			const ChordScale Mode(const size_t root, const size_t mode_num) const;
			const ChordScale PrimaryMode(const size_t root) const;
			const ChordScale PrimaryMode(const std::wstring& root) const;
		};
	}
}