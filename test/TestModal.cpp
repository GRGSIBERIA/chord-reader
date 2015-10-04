#include <Modal.hpp>
#include "gtest\gtest.h"
using namespace score::scale;

TEST(TestModal, int_to_string_sharp)
{
	EXPECT_EQ(Modalize::ToString(0), L"C");
	EXPECT_EQ(Modalize::ToString(1), L"C#");
	EXPECT_EQ(Modalize::ToString(2), L"D");
	EXPECT_EQ(Modalize::ToString(3), L"D#");
	EXPECT_EQ(Modalize::ToString(4), L"E");
	EXPECT_EQ(Modalize::ToString(5), L"F");
	EXPECT_EQ(Modalize::ToString(6), L"F#");
	EXPECT_EQ(Modalize::ToString(7), L"G");
	EXPECT_EQ(Modalize::ToString(8), L"G#");
	EXPECT_EQ(Modalize::ToString(9), L"A");
	EXPECT_EQ(Modalize::ToString(10), L"A#");
	EXPECT_EQ(Modalize::ToString(11), L"B");
}

TEST(TestModal, int_to_string_flat)
{
	EXPECT_EQ(Modalize::ToString(0, false), L"C");
	EXPECT_EQ(Modalize::ToString(1, false), L"Db");
	EXPECT_EQ(Modalize::ToString(2, false), L"D");
	EXPECT_EQ(Modalize::ToString(3, false), L"Eb");
	EXPECT_EQ(Modalize::ToString(4, false), L"E");
	EXPECT_EQ(Modalize::ToString(5, false), L"F");
	EXPECT_EQ(Modalize::ToString(6, false), L"Gb");
	EXPECT_EQ(Modalize::ToString(7, false), L"G");
	EXPECT_EQ(Modalize::ToString(8, false), L"Ab");
	EXPECT_EQ(Modalize::ToString(9, false), L"A");
	EXPECT_EQ(Modalize::ToString(10,false), L"Bb");
	EXPECT_EQ(Modalize::ToString(11,false), L"B");
}

TEST(TestModal, modal_to_string_sharp)
{
	EXPECT_EQ(Modalize::ToString(Modal::C), L"C");
	EXPECT_EQ(Modalize::ToString(Modal::CSharp), L"C#");
	EXPECT_EQ(Modalize::ToString(Modal::D), L"D");
	EXPECT_EQ(Modalize::ToString(Modal::DSharp), L"D#");
	EXPECT_EQ(Modalize::ToString(Modal::E), L"E");
	EXPECT_EQ(Modalize::ToString(Modal::F), L"F");
	EXPECT_EQ(Modalize::ToString(Modal::FSharp), L"F#");
	EXPECT_EQ(Modalize::ToString(Modal::G), L"G");
	EXPECT_EQ(Modalize::ToString(Modal::GSharp), L"G#");
	EXPECT_EQ(Modalize::ToString(Modal::A), L"A");
	EXPECT_EQ(Modalize::ToString(Modal::ASharp), L"A#");
	EXPECT_EQ(Modalize::ToString(Modal::B), L"B");
}

TEST(TestModal, modal_to_string_flat)
{
	EXPECT_EQ(Modalize::ToString(Modal::C, false), L"C");
	EXPECT_EQ(Modalize::ToString(Modal::DFlat, false), L"Db");
	EXPECT_EQ(Modalize::ToString(Modal::D, false), L"D");
	EXPECT_EQ(Modalize::ToString(Modal::EFlat, false), L"Eb");
	EXPECT_EQ(Modalize::ToString(Modal::E, false), L"E");
	EXPECT_EQ(Modalize::ToString(Modal::F, false), L"F");
	EXPECT_EQ(Modalize::ToString(Modal::GFlat, false), L"Gb");
	EXPECT_EQ(Modalize::ToString(Modal::G, false), L"G");
	EXPECT_EQ(Modalize::ToString(Modal::AFlat, false), L"Ab");
	EXPECT_EQ(Modalize::ToString(Modal::A, false), L"A");
	EXPECT_EQ(Modalize::ToString(Modal::BFlat, false), L"Bb");
	EXPECT_EQ(Modalize::ToString(Modal::B, false), L"B");
}

TEST(TestModal, string_to_int_sharp)
{
	EXPECT_EQ(Modalize::ToInt(L"C"), 0);
	EXPECT_EQ(Modalize::ToInt(L"C#"), 1);
	EXPECT_EQ(Modalize::ToInt(L"D"), 2);
	EXPECT_EQ(Modalize::ToInt(L"D#"), 3);
	EXPECT_EQ(Modalize::ToInt(L"E"), 4);
	EXPECT_EQ(Modalize::ToInt(L"F"), 5);
	EXPECT_EQ(Modalize::ToInt(L"F#"), 6);
	EXPECT_EQ(Modalize::ToInt(L"G"), 7);
	EXPECT_EQ(Modalize::ToInt(L"G#"), 8);
	EXPECT_EQ(Modalize::ToInt(L"A"), 9);
	EXPECT_EQ(Modalize::ToInt(L"A#"), 10);
	EXPECT_EQ(Modalize::ToInt(L"B"), 11);
}

TEST(TestModal, string_to_int_flat)
{
	EXPECT_EQ(Modalize::ToInt(L"C"), 0);
	EXPECT_EQ(Modalize::ToInt(L"Db"), 1);
	EXPECT_EQ(Modalize::ToInt(L"D"), 2);
	EXPECT_EQ(Modalize::ToInt(L"Eb"), 3);
	EXPECT_EQ(Modalize::ToInt(L"E"), 4);
	EXPECT_EQ(Modalize::ToInt(L"F"), 5);
	EXPECT_EQ(Modalize::ToInt(L"Gb"), 6);
	EXPECT_EQ(Modalize::ToInt(L"G"), 7);
	EXPECT_EQ(Modalize::ToInt(L"Ab"), 8);
	EXPECT_EQ(Modalize::ToInt(L"A"), 9);
	EXPECT_EQ(Modalize::ToInt(L"Bb"), 10);
	EXPECT_EQ(Modalize::ToInt(L"B"), 11);
}

TEST(TestModal, has_minor)
{
	EXPECT_EQ(Modalize::HasMinor(L"C"),  false);
	EXPECT_EQ(Modalize::HasMinor(L"Db"), false);
	EXPECT_EQ(Modalize::HasMinor(L"D"),  false);
	EXPECT_EQ(Modalize::HasMinor(L"Eb"), false);
	EXPECT_EQ(Modalize::HasMinor(L"E"),  false);
	EXPECT_EQ(Modalize::HasMinor(L"F"),  false);
	EXPECT_EQ(Modalize::HasMinor(L"Gb"), false);
	EXPECT_EQ(Modalize::HasMinor(L"G"),  false);
	EXPECT_EQ(Modalize::HasMinor(L"Ab"), false);
	EXPECT_EQ(Modalize::HasMinor(L"A"),  false);
	EXPECT_EQ(Modalize::HasMinor(L"Bb"), false);
	EXPECT_EQ(Modalize::HasMinor(L"B"),  false);

	EXPECT_EQ(Modalize::HasMinor(L"Cm"),  true);
	EXPECT_EQ(Modalize::HasMinor(L"Dbm"), true);
	EXPECT_EQ(Modalize::HasMinor(L"Dm"),  true);
	EXPECT_EQ(Modalize::HasMinor(L"Ebm"), true);
	EXPECT_EQ(Modalize::HasMinor(L"Em"),  true);
	EXPECT_EQ(Modalize::HasMinor(L"Fm"),  true);
	EXPECT_EQ(Modalize::HasMinor(L"Gbm"), true);
	EXPECT_EQ(Modalize::HasMinor(L"Gm"),  true);
	EXPECT_EQ(Modalize::HasMinor(L"Abm"), true);
	EXPECT_EQ(Modalize::HasMinor(L"Am"),  true);
	EXPECT_EQ(Modalize::HasMinor(L"Bbm"), true);
	EXPECT_EQ(Modalize::HasMinor(L"Bm"),  true);
}