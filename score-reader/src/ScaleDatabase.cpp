#include "ScaleDatabase.hpp"
#include "Modulation.hpp"
using namespace score::scale;

const std::array<KeyChordModalizer, 12> ScaleDatabase::major = { {
	KeyChordModalizer(L"C"),
	KeyChordModalizer(L"C#"),
	KeyChordModalizer(L"D"),
	KeyChordModalizer(L"D#"),
	KeyChordModalizer(L"E"),
	KeyChordModalizer(L"F"),
	KeyChordModalizer(L"F#"),
	KeyChordModalizer(L"G"),
	KeyChordModalizer(L"G#"),
	KeyChordModalizer(L"A"),
	KeyChordModalizer(L"A#"),
	KeyChordModalizer(L"B")
		} };

const std::array<KeyChordModalizer, 12> ScaleDatabase::minor = { {
	KeyChordModalizer(L"Cm"),
	KeyChordModalizer(L"C#m"),
	KeyChordModalizer(L"Dm"),
	KeyChordModalizer(L"D#m"),
	KeyChordModalizer(L"Em"),
	KeyChordModalizer(L"Fm"),
	KeyChordModalizer(L"F#m"),
	KeyChordModalizer(L"Gm"),
	KeyChordModalizer(L"G#m"),
	KeyChordModalizer(L"Am"),
	KeyChordModalizer(L"A#m"),
	KeyChordModalizer(L"Bm")
		} };

const KeyChordModalizer& ScaleDatabase::Find(const std::wstring& key)
{
	return Find(Modalize::ToInt(key), Modalize::HasMajor(key));
}
const KeyChordModalizer& ScaleDatabase::Find(const int modal, const bool isMajor)
{
	if (isMajor)
		return major[(size_t)modal];
	return minor[(size_t)modal];
}
const KeyChordModalizer& ScaleDatabase::Find(const Modal modal, const bool isMajor)
{
	return Find((int)modal, isMajor);
}
const KeyChordModalizer& ScaleDatabase::Major(const std::wstring& key)
{
	return Find(Modalize::ToInt(key), true);
}
const KeyChordModalizer& ScaleDatabase::Minor(const std::wstring& key)
{
	return Find(Modalize::ToInt(key), false);
}

const KeyChordModalizer& ScaleDatabase::Parallel(const std::wstring& key)
{
	return Find(Modulation::Parallel(key));
}
const KeyChordModalizer& ScaleDatabase::Relative(const std::wstring& key)
{
	return Find(Modulation::Relative(key));
}
const KeyChordModalizer& ScaleDatabase::Dominant(const std::wstring& key)
{
	return Find(Modulation::Dominant(key));
}
const KeyChordModalizer& ScaleDatabase::Subdominant(const std::wstring& key)
{
	return Find(Modulation::SubDominant(key));
}
const KeyChordModalizer& ScaleDatabase::MinorDominant(const std::wstring& key)
{
	return Find(Modulation::MinorDominant(key));
}
const KeyChordModalizer& ScaleDatabase::MinorSubdominant(const std::wstring& key)
{
	return Find(Modulation::MinorSubDominant(key));
}