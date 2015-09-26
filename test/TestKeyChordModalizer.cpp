#include "gtest\gtest.h"
#include <KeyChordModalizer.hpp>
using namespace score::scale;

const ModeTheory test_c(Scale(L"major", { 0, 2, 4, 5, 7, 9, 11 }), { 0, 2, 4, 6 });

void TestInterval(const ModalIndices& scale, const std::vector<int>& interval)
{
	for (size_t i = 0; i < scale.size(); ++i)
	{
		EXPECT_EQ(scale[i], interval[i]);
	}
}

void TestScale(const KeyChordModalizer& modal, const std::wstring& str, const std::vector<int>& comp)
{
	const auto& scale = modal.GetPrimaryMode(str);

	TestInterval(scale, comp);
}

TEST(TestKeyChordModalizer, test_primary_mode)
{
	const auto modal = KeyChordModalizer(Modal::C, test_c);

	TestScale(modal, L"CM7", { 0, 2, 4, 5, 7, 9, 11 });
	TestScale(modal, L"Dm7", { 2, 4, 5, 7, 9, 11, 0 });
}