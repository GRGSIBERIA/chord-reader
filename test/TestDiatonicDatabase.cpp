#include "gtest\gtest.h"
#include <DiatonicDatabase.hpp>

const auto& diatonic = score::chord::DiatonicDatabase::GetInstance();

void Expect(const size_t i, const std::wstring tone, const std::wstring fifth, const std::wstring dominant)
{
	const auto& c = diatonic.GetChord(i);
	EXPECT_EQ(c.tone.Name(), tone);
	EXPECT_EQ(c.fifth.Name(), fifth);
	EXPECT_EQ(c.dominant.Name(), dominant);
}

void ExpectMinor(const size_t i, const std::wstring tone, const std::wstring fifth, const std::wstring dominant)
{
	const auto& c = diatonic.GetChord(i, false);
	EXPECT_EQ(c.tone.Name(), tone);
	EXPECT_EQ(c.fifth.Name(), fifth);
	EXPECT_EQ(c.dominant.Name(), dominant);
}

TEST(TestDiatonicDatabase, test_c)
{
	Expect(0, L"", L"", L"M7");
}

TEST(TestDiatonicDatabase, test_d)
{
	Expect(1, L"m", L"", L"7");
}

TEST(TestDiatonicDatabase, test_e)
{
	Expect(2, L"m", L"", L"7");
}

TEST(TestDiatonicDatabase, test_f)
{
	Expect(3, L"", L"", L"M7");
}

TEST(TestDiatonicDatabase, test_g)
{
	Expect(4, L"", L"", L"7");
}

TEST(TestDiatonicDatabase, test_a)
{
	Expect(5, L"m", L"", L"7");
}

TEST(TestDiatonicDatabase, test_b)
{
	Expect(6, L"m", L"-5", L"7");
}

TEST(TestDiatonicDatabase, test_cm)
{
	ExpectMinor(0, L"m", L"", L"7");
}

TEST(TestDiatonicDatabase, test_dm)
{
	ExpectMinor(1, L"m", L"-5", L"7");
}

TEST(TestDiatonicDatabase, test_em)
{
	ExpectMinor(2, L"", L"", L"M7");
}

TEST(TestDiatonicDatabase, test_fm)
{
	ExpectMinor(3, L"m", L"", L"7");
}

TEST(TestDiatonicDatabase, test_gm)
{
	ExpectMinor(4, L"m", L"", L"7");
}

TEST(TestDiatonicDatabase, test_am)
{
	ExpectMinor(5, L"", L"", L"M7");
}

TEST(TestDiatonicDatabase, test_bm)
{
	ExpectMinor(6, L"", L"", L"7");
}