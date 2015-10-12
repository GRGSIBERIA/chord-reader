#include "KeyChordModalizer.hpp"
using namespace score::scale;

const ScaleTheory KeyChordModalizer::majtheory = ScaleTheory({ 0, 2, 4, 5, 7, 9, 11 });
const ScaleTheory KeyChordModalizer::mintheory = ScaleTheory({ 0, 2, 3, 5, 7, 8, 11 });

int RoundInterval(int num)
{
	if (num > 11) return RoundInterval(num - 12);
	else if (num < 0) return RoundInterval(num + 12);
	return num;
}

void KeyChordModalizer::CalcModeScalesOnRoot(const size_t root)
{
	for (size_t modeIndex = 0; modeIndex < scale.Size(); ++modeIndex)
	{
		const auto& mode = mtheory.GetMode(modeIndex);

		for (size_t intervalIndex = 0; intervalIndex < scale.Size(); ++intervalIndex)
		{
			int tmp = mode.GetInterval(intervalIndex) + (int)key + scale.GetInterval(root);
			tmp = RoundInterval(tmp);

			modeScale[root][modeIndex][intervalIndex] = tmp;
		}
	}
}

void KeyChordModalizer::CalcAvailableScaleOnRoot(const size_t root)
{
	const auto& primary = modeScale[root][root];
	const auto& availableOnMode = mtheory.GetMode(root).GetAvailableScale();

	for (size_t modeIndex = 0; modeIndex < scale.Size(); ++modeIndex)
	{
		const auto& targetScale = modeScale[root][modeIndex];
		const auto& targetMode = mtheory.GetMode(modeIndex);

		for (size_t intervalIndex = 0; intervalIndex < scale.Size(); ++intervalIndex)
		{
			// Available Note�ȊO�͒ǉ����Ȃ����j
			if (availableOnMode[intervalIndex] != targetMode.GetInterval(intervalIndex))
				continue;

			availables[root][modeIndex].push_back(targetScale[intervalIndex]);
		}
	}
}

KeyChordModalizer::KeyChordModalizer(const std::wstring& key) 
	: KeyChordModalizer(key, Modalize::ToModal(key), Modalize::HasMinor(key) ? mintheory : majtheory, { 0, 2, 4, 6 })
{
	// �Ϗ��R���X�g���N�^
}

KeyChordModalizer::KeyChordModalizer(const std::wstring& keyName, const Modal& key, const ScaleTheory& theory, const ScaleIndices& chordTone)
	: mtheory(Scale(keyName, theory.GetScale(key)), chordTone), key(key), scale(keyName, theory.GetScale(key)), keyName(keyName)
{
	modeScale = ModesOnScale(scale.Size(), 
		ModeModalScales(scale.Size(), 
		ModeModals(scale.Size())));
	availables = ModesOnScale(scale.Size(),
		ModeModalScales(scale.Size()));

	// ���K���ƂɃ��[�h�X�P�[����W�J����

	for (size_t root = 0; root < scale.Size(); ++root)
	{
		// ���̃��[�v�ŁC���郋�[�g���ɑΉ����邷�ׂẴ��[�h�X�P�[�������߂�
		CalcModeScalesOnRoot(root);

		// ���̃��[�v�ŁC���[�h���Ƃɉ��t�\�Ȋy����ǉ�����
		CalcAvailableScaleOnRoot(root);
	}
}

const ModeModals& KeyChordModalizer::PrimaryModeScale(const std::wstring& str) const
{
	auto index = scale.GetIndex(str);
	return ModeScale(index, index);
}

const ModeModals& KeyChordModalizer::PrimaryAvailableScale(const std::wstring& str) const
{
	auto index = scale.GetIndex(str);
	return AvailableScale(index, index);
}

const ModeModals& KeyChordModalizer::AvailableScale(const std::wstring& str, const size_t mode_num) const
{
	auto index = scale.GetIndex(str);
	return AvailableScale(index, mode_num);
}

const ModeModals& KeyChordModalizer::ModeScale(const std::wstring& str, const size_t mode_num) const
{
	auto index = scale.GetIndex(str);
	return ModeScale(index, mode_num);
}

const ModeModalScales& KeyChordModalizer::Availables(const std::wstring& chord) const
{
	return availables[scale.GetIndex(chord)];
}