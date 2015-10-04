#pragma once
#include <map>
#include "KeyChordModalizer.hpp"
#include "Score.hpp"

namespace score
{
	namespace score
	{
		class ScaleManager
		{
			typedef std::shared_ptr<scale::KeyChordModalizer> KCMPtr;
			std::map<std::wstring, KCMPtr> keys;

		public:
			ScaleManager(const Score& score);

			// �A�x�C���u���X�P�[���̈ꗗ���擾����
			const scale::ModeModalScales& GetScale(const std::wstring& key, const std::wstring& chord) { return keys[key]->GetAvailables(chord); }

			// ���݂̃R�[�h�̃��[�h�C���f�b�N�X���擾����
			const int GetIndexOnScale(const std::wstring& key, const std::wstring& chord) { return keys[key]->ModeIndex(chord); }
		};
	}
}