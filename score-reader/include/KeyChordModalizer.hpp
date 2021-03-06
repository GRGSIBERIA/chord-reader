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
		// 利用するマイナーキーの種類
		enum class MinorType
		{
			Natural,
			Harmonic,
			Melodic
		};

		// あるキーのモードスケールを管理するクラス
		class KeyChordModalizer
		{
			static const ScaleTheory majtheory;
			static const ScaleTheory harmonic;
			static const ScaleTheory natural;
			static const ScaleTheory melodic;
			static const ScaleTheory* current;

			const ModeTheory mtheory;

			const Scale scale;

			const Modal key;

			const std::wstring keyName;

			const MinorType minorType;

			ModesOnScale modeScale;
			ModesOnScale usables;
			ModesOnScale availables;

			void CalcModeScalesOnRoot(const size_t root);
			void CalcAvailableScaleOnRoot(const size_t root);
			const ScaleTheory& GetMinor(const MinorType minor) const;
			void RoundUsableScale(const size_t root);

		public:
			KeyChordModalizer(const std::wstring& keyName, const Modal& key, const ScaleTheory& theory, const ScaleIndices& chordTone, const MinorType minor = MinorType::Harmonic);
			KeyChordModalizer(const std::wstring& key);
			KeyChordModalizer(const std::wstring& key, const MinorType minor);

			// モードを取得する
			const ModeModals& ModeScale(const size_t root, const size_t mode_num) const;
			const ModeModals& ModeScale(const std::wstring& str, const size_t mode_num) const;

			// 現在のコードに対して主体的なモードを返す
			const ModeModals& PrimaryModeScale(const std::wstring& str) const;
			const ModeModals& PrimaryModeScale(const size_t rootIndex) const;

			// アベイラブルスケールを取得する
			const ModeModals& AvailableScale(const size_t root, const size_t mode_num) const;
			const ModeModals& AvailableScale(const std::wstring& str, const size_t mode_num) const;

			// 現在のコードに対して主体的なアベイラブルスケールを返す
			const ModeModals& PrimaryAvailableScale(const std::wstring& str) const;
			const ModeModals& PrimaryAvailableScale(const size_t rootIndex) const;

			// 現在のコードに対して使用可能な音階を返す
			const ModeModals& UsableScale(const size_t rootIndex, const size_t mode_num) const;
			const ModeModals& UsableScale(const std::wstring& str, const size_t mode_num) const;

			// 現在のコードに対して主体的で使用可能な音階を返す
			const ModeModals& PrimaryUsableScale(const size_t rootIndex) const;
			const ModeModals& PrimaryUsableScale(const std::wstring& str) const;

			// あるコードにおけるモードスケールの中で，アベイラブルスケールをすべて取得する
			const ModeModalScales& Availables(const std::wstring& chord) const;

			// コードからモードインデックスを返す
			const int ModeIndex(const std::wstring& chord) const { return scale.GetIndex(chord); }

			GET_PROPERTY(const std::wstring&, KeyName, keyName);
			GET_PROPERTY(const DiatonicChords&, Diatonics, mtheory.Diatonics);
			GET_PROPERTY(const MinorType, Minor, minorType);

			const ChordScale Mode(const std::wstring& chord, const size_t mode_num) const;
			const ChordScale Mode(const size_t root, const size_t mode_num) const;
			const ChordScale PrimaryMode(const size_t root) const;
			const ChordScale PrimaryMode(const std::wstring& root) const;

			static void ChangeCurrentMinorScale(const MinorType minor);
		};
	}
}