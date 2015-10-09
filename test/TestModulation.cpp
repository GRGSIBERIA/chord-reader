#include "gtest\gtest.h"
#include <Modulation.hpp>
using namespace score::scale;

TEST(TestModulation, parallel)
{
	std::vector<std::wstring> strs = { L"C", L"D", L"E", L"F", L"G", L"A", L"B" };
	std::vector<std::wstring> min;

	for (const auto& str : strs)
		EXPECT_EQ(Modulation::Parallel(str), str + L"m");

	for (auto& str : strs) min.push_back(str + L"m");

	for (size_t i = 0; i < strs.size(); ++i)
		EXPECT_EQ(Modulation::Parallel(min[i]), strs[i]);
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