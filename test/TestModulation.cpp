#include "gtest\gtest.h"
#include <iostream>
#include <fstream>
#include <Modulation.hpp>
using namespace score::scale;
using namespace std;

TEST(TestModulation, parallel)
{
	std::vector<std::wstring> strs = { L"C", L"D", L"E", L"F", L"G", L"A", L"B" };
	std::vector<std::wstring> min;

	for (const auto& str : strs)
		EXPECT_EQ(Modulation::Parallel(str), str + L"m");

	for (auto& str : strs) min.push_back(str + L"m");

	for (size_t i = 0; i < strs.size(); ++i)
		EXPECT_EQ(Modulation::Parallel(min[i]), strs[i]);

	EXPECT_EQ(Modulation::Parallel(L"C#"), L"C#m");
	EXPECT_EQ(Modulation::Parallel(L"Db"), L"Dbm");
}

TEST(TestModulation, dominant)
{
	EXPECT_EQ(Modulation::Dominant(L"C"), L"G");
	EXPECT_EQ(Modulation::Dominant(L"D"), L"A");
	EXPECT_EQ(Modulation::Dominant(L"Cm"), L"Gm");
	EXPECT_EQ(Modulation::Dominant(L"Dm"), L"Am");
}

TEST(TestModulation, relative)
{
	EXPECT_EQ(Modulation::Relative(L"C"), L"Am");
	EXPECT_EQ(Modulation::Relative(L"D"), L"Bm");
	EXPECT_EQ(Modulation::Relative(L"Cm"), L"E");
	EXPECT_EQ(Modulation::Relative(L"Dm"), L"F#");
}

TEST(TestModulation, subdominant)
{
	EXPECT_EQ(Modulation::SubDominant(L"C"), L"F");
	EXPECT_EQ(Modulation::SubDominant(L"D"), L"G");
	EXPECT_EQ(Modulation::SubDominant(L"Cm"), L"Fm");
	EXPECT_EQ(Modulation::SubDominant(L"Dm"), L"Gm");
}

TEST(TestModulation, secondary)
{
	EXPECT_EQ(Modulation::SecondaryDominant(L"CM7", false).Chord.Name(), L"G7");
	EXPECT_EQ(Modulation::SecondaryDominant(L"Dm7", false).Chord.Name(), L"A7");
	EXPECT_EQ(Modulation::SecondaryDominant(L"Em7", false).Chord.Name(), L"B7");
	EXPECT_EQ(Modulation::SecondaryDominant(L"FM7", false).Chord.Name(), L"C7");
	EXPECT_EQ(Modulation::SecondaryDominant(L"G7", false).Chord.Name(), L"D7");
	EXPECT_EQ(Modulation::SecondaryDominant(L"Am7", false).Chord.Name(), L"E7");
	EXPECT_EQ(Modulation::SecondaryDominant(L"Bm7-5", false).Chord.Name(), L"Gb7");

	EXPECT_EQ(Modulation::SecondaryDominant(L"CM7", true).Key, L"Cm");
	EXPECT_EQ(Modulation::SecondaryDominant(L"Dm7", true).Key, L"Dm");
	EXPECT_EQ(Modulation::SecondaryDominant(L"Em7", true).Key, L"Em");
	EXPECT_EQ(Modulation::SecondaryDominant(L"FM7", true).Key, L"Fm");
	EXPECT_EQ(Modulation::SecondaryDominant(L"G7", true ).Key, L"Gm");
	EXPECT_EQ(Modulation::SecondaryDominant(L"Am7", true).Key, L"Am");
	EXPECT_EQ(Modulation::SecondaryDominant(L"Bm7-5", true).Key, L"Bm");
}

std::wstring RelatesToString(const RelatedKey key)
{
	switch (key)
	{
	case RelatedKey::Parallel:
		return L"Parallel";
	case RelatedKey::Relative:
		return L"Relative";
	case RelatedKey::Dominant:
		return L"Dominant";
	case RelatedKey::Subdominant:
		return L"Subdominant";
	case RelatedKey::MinorDominant:
		return L"mDominant";
	case RelatedKey::MinorSubdominant:
		return L"mSubdominant";
	default:
		return L"";
	}
}

TEST(TestModulation, interchange)
{
	// キーの各コードより，平行調にモーダルチェンジした場合の結果
	// 現実で計算するの凄く面倒くさいので，ダンプする

	std::wofstream ofst(L"./dump/modal_interchange.csv", std::ios::out);
	std::vector<std::wstring> keys = { L"C", L"C#", L"D", L"D#", L"E", L"F", L"F#", L"G", L"G#", L"A", L"A#", L"B" };
	std::vector<RelatedKey> relates = { RelatedKey::Parallel, RelatedKey::Relative, RelatedKey::Dominant, RelatedKey::Subdominant, RelatedKey::MinorDominant, RelatedKey::MinorSubdominant };

	std::wstring header = L"key,changed,related,intervals\n";
	ofst.write(header.c_str(), header.size());

	for (const auto& key : keys)
	{
		for (const auto& relate : relates)
		{
			for (size_t i = 0; i < 7; ++i)
			{
				auto k = std::wstring();
				const auto& mod = Modulation::ModalInterchange(key, i, relate);

				if (i == 0)
				{
					k += key + L",";
					k += mod.Key + L",";
					k += RelatesToString(relate) + L",";
				}
				k += mod.Chord.Name() + L",";
				ofst.write(k.c_str(), k.size());
			}
			auto end = std::wstring(L"\n");
			ofst.write(end.c_str(), end.size());
		}
	}
}

TEST(TestModulation, substitute)
{
	EXPECT_EQ(Modulation::SubstituteDominant(L"C", L"G7").Chord.Name(), L"Db7");
}