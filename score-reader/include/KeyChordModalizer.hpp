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
		// ���p����}�C�i�[�L�[�̎��
		enum class MinorType
		{
			Natural,
			Harmonic,
			Melodic
		};

		// ����L�[�̃��[�h�X�P�[�����Ǘ�����N���X
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

		public:
			KeyChordModalizer(const std::wstring& keyName, const Modal& key, const ScaleTheory& theory, const ScaleIndices& chordTone, const MinorType minor = MinorType::Harmonic);
			KeyChordModalizer(const std::wstring& key);
			KeyChordModalizer(const std::wstring& key, const MinorType minor);

			// ���[�h���擾����
			const ModeModals& ModeScale(const size_t root, const size_t mode_num) const { return modeScale[root][mode_num]; }
			const ModeModals& ModeScale(const std::wstring& str, const size_t mode_num) const;

			// ���݂̃R�[�h�ɑ΂��Ď�̓I�ȃ��[�h��Ԃ�
			const ModeModals& PrimaryModeScale(const std::wstring& str) const;
			const ModeModals& PrimaryModeScale(const size_t rootIndex) const { return modeScale[rootIndex][rootIndex]; }

			// �A�x�C���u���X�P�[�����擾����
			const ModeModals& AvailableScale(const size_t root, const size_t mode_num) const { return availables[root][mode_num]; }
			const ModeModals& AvailableScale(const std::wstring& str, const size_t mode_num) const;

			// ����R�[�h�ɂ����郂�[�h�X�P�[���̒��ŁC�A�x�C���u���X�P�[�������ׂĎ擾����
			const ModeModalScales& Availables(const std::wstring& chord) const;

			// ���݂̃R�[�h�ɑ΂��Ď�̓I�ȃA�x�C���u���X�P�[����Ԃ�
			const ModeModals& PrimaryAvailableScale(const std::wstring& str) const;
			const ModeModals& PrimaryAvailableScale(const size_t rootIndex) const { return availables[rootIndex][rootIndex]; }

			// �R�[�h���烂�[�h�C���f�b�N�X��Ԃ�
			const int ModeIndex(const std::wstring& chord) const { return scale.GetIndex(chord); }

			GET_PROPERTY(const std::wstring&, KeyName, keyName);
			GET_PROPERTY(const DiatonicChords&, Diatonics, mtheory.Diatonics);
			GET_PROPERTY(const MinorType, Minor, minorType);

			const ChordScale Mode(const std::wstring& chord, const size_t mode_num) const;
			const ChordScale Mode(const size_t root, const size_t mode_num) const;
			const ChordScale PrimaryMode(const size_t root) const;
			const ChordScale PrimaryMode(const std::wstring& root) const;
		};
	}
}