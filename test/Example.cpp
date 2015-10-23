#include "gtest\gtest.h"
#include <iostream>
#include <ChordScore.hpp>
#include <Modulation.hpp>
using namespace std;

TEST(Example, example)
{
	auto autumn = score::score::ChordScore("..\\autumn leaves.xml");

	const auto& first = autumn.Chords[0];

	wcout << first.Chord << endl;
	for (size_t i = 0; i < 7; ++i)
	{
		const auto& mode = first.Scale(i);	// ���[�h�X�P�[�����擾

		for (const auto u : mode)
			wcout << u << L",";
		wcout << endl;
	}

	for (size_t i = 0; i < 7; ++i)
	{
		const auto& mode = first.Usable(i);	// �A�{�C�h��������X�P�[�����擾

		for (const auto u : mode)
			wcout << u << L",";
		wcout << endl;
	}

	const auto& next = autumn.Chords.NextPart(autumn.Chords.begin());	//���̃p�[�g�̈ʒu��Ԃ�

	// ���s���Ƀ��[�_���C���^�[�`�F���W����
	const auto& interchanged = score::scale::Modulation::ModalInterchange(next->Key, next->Chord, score::scale::RelatedKey::Parallel);
}