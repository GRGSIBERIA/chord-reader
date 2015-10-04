#include "gtest\gtest.h"
#include <KeyChordModalizer.hpp>
#include <iostream>

using namespace score::scale;
using namespace std;


void PrintModeScale(const ScaleTheory& scaleTheory, Modal key, int modeIndex, const std::vector<int>& comp)
{
	const Scale scale = Scale(L"", scaleTheory.GetScale(key));
	const ModeTheory modeTheory = ModeTheory(scale, { 0, 2, 4, 6 });

	const auto& mode = modeTheory.GetMode(modeIndex);

	for (size_t i = 0; i < mode.Size(); ++i)
	{
		int tmp = mode.GetInterval(i) + (int)key;
		tmp = tmp > 11 ? tmp - 12 : tmp;
		//wcout << Modalize::ToString(tmp, false) << L",";
		EXPECT_EQ(tmp, comp[i]);
	}
	//cout << endl;
}

TEST(TestKeyChordModalizer, test_scale_for_mode)
{
	const ScaleTheory scaleTheory = ScaleTheory({0, 2, 4, 5, 7, 9, 11});

	PrintModeScale(scaleTheory, Modal::C, 0, { 0, 2, 4, 5, 7, 9, 11 });
	PrintModeScale(scaleTheory, Modal::D, 1, { 2, 4, 5, 7, 9, 11, 0 });
	PrintModeScale(scaleTheory, Modal::E, 2, { 4, 5, 7, 9, 11, 0, 2 });
	PrintModeScale(scaleTheory, Modal::F, 3, { 5, 7, 9, 11, 0, 2, 4 });
	PrintModeScale(scaleTheory, Modal::G, 4, { 7, 9, 11, 0, 2, 4, 5 });
	PrintModeScale(scaleTheory, Modal::A, 5, { 9, 11, 0, 2, 4, 5, 7 });
	PrintModeScale(scaleTheory, Modal::B, 6, { 11, 0, 2, 4, 5, 7, 9 });
}

void PrintVector(const KeyChordModalizer& modalizer, size_t root, size_t mode, const std::vector<int>& comp)
{
	const auto& v = modalizer.GetModeScale(root, mode);
	for (size_t i = 0; i < v.size(); ++i)
		//wcout << Modalize::ToString(v[i]) << ",";
		EXPECT_EQ(v[i], comp[i]);
	//cout << endl;
}

TEST(TestKeyChordModalizer, get_modals_on_c)
{
	const auto modalizer = KeyChordModalizer(L"C");

	PrintVector(modalizer, 0, 0, { 0, 2, 4, 5, 7, 9, 11 });
	PrintVector(modalizer, 1, 1, { 2, 4, 5, 7, 9, 11, 0 });
	PrintVector(modalizer, 2, 2, { 4, 5, 7, 9, 11, 0, 2 });
	PrintVector(modalizer, 3, 3, { 5, 7, 9, 11, 0, 2, 4 });
	PrintVector(modalizer, 4, 4, { 7, 9, 11, 0, 2, 4, 5 });
	PrintVector(modalizer, 5, 5, { 9, 11, 0, 2, 4, 5, 7 });
	PrintVector(modalizer, 6, 6, { 11, 0, 2, 4, 5, 7, 9 });
}

void PrintAvailables(const KeyChordModalizer& modalizer, const size_t key, const size_t modal, const std::vector<int>& comp)
{
	const auto& v = modalizer.GetAvailableScale(key, modal);

	for (size_t i = 0; i < v.size(); ++i)
		//wcout << Modalize::ToString(v[i]) << ",";
		EXPECT_EQ(v[i], comp[i]);
	//cout << endl;
}

TEST(TestKeyChordModalizer, test_availables)
{
	const auto modalizer = KeyChordModalizer(L"C");

	PrintAvailables(modalizer, 0, 0, { 0, 2, 4, 7, 9, 11 });
	PrintAvailables(modalizer, 1, 1, { 2, 4, 5, 7, 9, 0 });
	PrintAvailables(modalizer, 2, 2, { 4, 7, 9, 11, 2 });
	PrintAvailables(modalizer, 3, 3, { 5, 7, 9, 11, 0, 2, 4 });
	PrintAvailables(modalizer, 4, 4, { 7, 9, 11, 2, 4, 5 });
	PrintAvailables(modalizer, 5, 5, { 9, 11, 0, 2, 4, 7 });
	PrintAvailables(modalizer, 6, 6, { 11, 2, 4, 5, 7, 9 });
}

void TestAvailables(const KeyChordModalizer& modalizer, const std::wstring& key, const size_t modal, const std::vector<int>& comp)
{
	const auto& v = modalizer.GetAvailableScale(key, modal);

	for (size_t i = 0; i < v.size(); ++i)
		EXPECT_EQ(v[i], comp[i]);
}

TEST(TestKeyChordModalizer, test_chord_name)
{
	const auto modalizer = KeyChordModalizer(L"C");

	TestAvailables(modalizer, L"CM7",	0, { 0, 2, 4, 7, 9, 11 });
	TestAvailables(modalizer, L"Dm7",	1, { 2, 4, 5, 7, 9, 0 });
	TestAvailables(modalizer, L"Em7",	2, { 4, 7, 9, 11, 2 });
	TestAvailables(modalizer, L"FM7",	3, { 5, 7, 9, 11, 0, 2, 4 });
	TestAvailables(modalizer, L"G7",	4, { 7, 9, 11, 2, 4, 5 });
	TestAvailables(modalizer, L"Am7",	5, { 9, 11, 0, 2, 4, 7 });
	TestAvailables(modalizer, L"Bm7-5", 6, { 11, 2, 4, 5, 7, 9 });
}