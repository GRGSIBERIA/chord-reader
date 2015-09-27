#include "gtest\gtest.h"
#include <KeyChordModalizer.hpp>
#include <iostream>

using namespace score::scale;
using namespace std;

const ModeTheory test_c(Scale(L"major", { 0, 2, 4, 5, 7, 9, 11 }), { 0, 2, 4, 6 });
const ModeTheory test_d(Scale(L"major", { 2, 4, 5, 7, 9, 11, 0 }), { 0, 2, 4, 6 });

void PrintInterval(size_t num, int modal)
{
	const auto& scale = test_c.GetMode(num);

	for (size_t i = 0; i < scale.Size(); ++i)
	{
		int tmp = scale.GetInterval(i) + (int)modal;
		tmp = tmp > 11 ? tmp - 12 : tmp;
		cout << tmp << ",";
	}
	cout << endl;
}

TEST(TestKeyChordModalizer, test_print_interval)
{
	PrintInterval(0, 0);
	PrintInterval(1, 2);
	PrintInterval(2, 4);
}

void PrintModeScale(const ScaleTheory& scaleTheory, Modal key, int modeIndex)
{
	const Scale scale = Scale(L"", scaleTheory.GetScale(key));
	const ModeTheory modeTheory = ModeTheory(scale, { 0, 2, 4, 6 });

	const auto& mode = modeTheory.GetMode(modeIndex);

	for (size_t i = 0; i < mode.Size(); ++i)
	{
		int tmp = mode.GetInterval(i) + (int)key;
		tmp = tmp > 11 ? tmp - 12 : tmp;
		wcout << Modalize::ToString(tmp, false) << L",";
	}
	cout << endl;
}

TEST(TestKeyChordModalizer, test_scale_for_mode)
{
	const ScaleTheory scaleTheory = ScaleTheory({0, 2, 4, 5, 7, 9, 11});

	PrintModeScale(scaleTheory, Modal::C, 0);
	PrintModeScale(scaleTheory, Modal::D, 1);
	PrintModeScale(scaleTheory, Modal::E, 2);
	PrintModeScale(scaleTheory, Modal::F, 3);
	PrintModeScale(scaleTheory, Modal::G, 4);
	PrintModeScale(scaleTheory, Modal::A, 5);
	PrintModeScale(scaleTheory, Modal::B, 6);
}

void PrintVector(const KeyChordModalizer& modalizer, size_t root, size_t mode)
{
	const auto& v = modalizer.GetModeModals(root, mode);
	for (size_t i = 0; i < v.size(); ++i)
		wcout << Modalize::ToString(v[i]) << ",";
	cout << endl;
}

TEST(TestKeyChordModalizer, get_modals_on_c)
{
	const auto modalizer = KeyChordModalizer(Modal::C);

	PrintVector(modalizer, 0, 0);
	PrintVector(modalizer, 1, 1);
	PrintVector(modalizer, 2, 2);
	PrintVector(modalizer, 3, 3);
	PrintVector(modalizer, 4, 4);
	PrintVector(modalizer, 5, 5);
	PrintVector(modalizer, 6, 6);
}

TEST(TestKeyChordModalizer, test_availables)
{
	const auto modalizer = KeyChordModalizer(Modal::C);
}