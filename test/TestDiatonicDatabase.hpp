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

TEST(TestDiatonicDatabase, test_c)
{
	Expect(0, L"", L"", L"M7");
}

TEST(TestDiatonicDatabase, test_d)
{
	Expect(0, L"m", L"", L"7");
}

TEST(TestDiatonicDatabase, test_e)
{
	Expect(0, L"m", L"", L"7");
}

TEST(TestDiatonicDatabase, test_f)
{
	Expect(0, L"", L"", L"M7");
}

TEST(TestDiatonicDatabase, test_g)
{
	Expect(0, L"", L"", L"7");
}

TEST(TestDiatonicDatabase, test_a)
{
	Expect(0, L"m", L"", L"7");
}

TEST(TestDiatonicDatabase, test_c)
{
	Expect(0, L"m", L"-5", L"7");
}