#pragma once
#include "Modal.hpp"
#include "ScaleTheory.hpp"
#include "Scale.hpp"
#include "ModeTheory.hpp"
#include <array>

namespace score
{
	namespace scale
	{
		typedef std::vector<int> ModeModals;
		typedef std::vector<ModeModals> ModeModalScales;
		typedef std::vector<ModeModalScales> ModesOnScale;

		class KeyChordModalizer
		{
			static const ScaleTheory stheory;

			const ModeTheory mtheory;

			const Scale scale;

			const Modal key;

			ModesOnScale modeScale;

			ModesOnScale availables;

			void CalcModeScalesOnRoot(const size_t root);
			void CalcAvailableScaleOnRoot(const size_t root);

		public:
			KeyChordModalizer(const Modal& key);

			// モードを取得する
			const ModeModals& GetModeScale(const size_t root, const size_t mode_num) const { return modeScale[root][mode_num]; }
			const ModeModals& GetModeScale(const std::wstring& str, const size_t mode_num) const;

			// 現在のコードに対して主体的なモードを返す
			const ModeModals& GetPrimaryModeScale(const std::wstring& str) const;
			const ModeModals& GetPrimaryModeScale(const size_t rootIndex) const { return modeScale[rootIndex][rootIndex]; }

			// アベイラブルスケールを取得する
			const ModeModals& GetAvailableScale(const size_t root, const size_t mode_num) const { return availables[root][mode_num]; }
			const ModeModals& GetAvailableScale(const std::wstring& str, const size_t mode_num) const;

			// 現在のコードに対して主体的なアベイラブルスケールを返す
			const ModeModals& GetPrimaryAvailableScale(const std::wstring& str) const;
			const ModeModals& GetPrimaryAvailableScale(const size_t rootIndex) const { return availables[rootIndex][rootIndex]; }
		};
	}
}