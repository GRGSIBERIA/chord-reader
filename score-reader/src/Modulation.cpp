#include "Modulation.hpp"
using namespace score::scale;

int Round(int num)
{
	if (num > 11) num -= 12;
	return num;
}
std::wstring SwapMinor(const bool hasminor)
{
	return !hasminor ? L"m" : L"";
}
std::wstring GetMinor(const std::wstring& str)
{
	return Modalize::HasMinor(str) ? L"m" : L"";
}
const std::wstring CalcTop(const std::wstring& str, int plus)
{
	auto num = Round(Modalize::ToInt(str) + plus);
	return Modalize::ToString(num) + GetMinor(str);
}
const std::wstring AccidentaledPlusSwap(const int num, const std::wstring& str, const bool hasm)
{
	const auto accidental = Modalize::HasAccidental(str);
	return Modalize::ToString(num, accidental >= 0 ? true : false) + SwapMinor(hasm);
}
const std::wstring CalcUnder(const std::wstring& str, int maj, int min)
{
	const bool hasm = Modalize::HasMinor(str);
	
	int num;
	if (!hasm)
		num = Round(Modalize::ToInt(str) + maj);
	else
		num = Round(Modalize::ToInt(str) + min);

	return AccidentaledPlusSwap(num, str, hasm);
}

const std::wstring Modulation::Parallel(const std::wstring& str)
{
	const auto num = Modalize::ToInt(str);
	return AccidentaledPlusSwap(num, str, Modalize::HasMinor(str));
}
const std::wstring Modulation::Relative(const std::wstring& str)
{
	return CalcUnder(str, 9, 4);
}
const std::wstring Modulation::Dominant(const std::wstring& str)
{
	return CalcTop(str, 7);
}
const std::wstring Modulation::SubDominant(const std::wstring& str)
{
	return CalcTop(str, 5);
}
const std::wstring Modulation::MinorDominant(const std::wstring& str)
{
	return CalcUnder(str, 4, 11);
}
const std::wstring Modulation::MinorSubDominant(const std::wstring& str)
{
	return CalcUnder(str, 5, 9);
}
const std::wstring Modulation::Modulate(const RelatedKey relate, const std::wstring& key)
{
	switch (relate)
	{
	case RelatedKey::Parallel:
		return Parallel(key);

	case RelatedKey::Relative:
		return Relative(key);

	case RelatedKey::Dominant:
		return Dominant(key);

	case RelatedKey::Subdominant:
		return SubDominant(key);

	case RelatedKey::MinorDominant:
		return MinorDominant(key);

	case RelatedKey::MinorSubdominant:
		return MinorSubDominant(key);
	}
	throw UndefinedRelatedKeyException();
}

const ChordScale Modulation::SecondaryDominant(const std::wstring& targetChord, const bool useMinor = false)
{
	const auto& secondaryKey = useMinor ? ScaleDatabase::Minor(targetChord) : ScaleDatabase::Major(targetChord);
	return secondaryKey.Mode(4, 4);
}

const ChordScale Modulation::ModalInterchange(const std::wstring& key, const int chordIndex, const RelatedKey related, const KeyChordModalizer& base)
{
	const auto& changed = ScaleDatabase::Modulate(key, related);

	const auto changedIndex = base.ModeIndex(changed.KeyName);

	int targetIndex = chordIndex < changedIndex ? chordIndex + 7 : chordIndex;

	return changed.PrimaryMode(targetIndex - changedIndex);
}

const ChordScale Modulation::ModalInterchange(const std::wstring& key, const std::wstring& chord, const RelatedKey related = RelatedKey::Parallel)
{
	const auto& base = ScaleDatabase::Find(key);

	const auto chordIndex = base.ModeIndex(chord);

	return ModalInterchange(key, chordIndex, related, base);
}

const ChordScale Modulation::ModalInterchange(const std::wstring& key, const size_t scaleIndex, const RelatedKey related)
{
	const auto& base = ScaleDatabase::Find(key);

	return ModalInterchange(key, scaleIndex, related, base);
}

const ChordScale SubstituteDominant(const std::wstring& key, const std::wstring& chord)
{
	const auto& base = ScaleDatabase::Find(key);

	const int chordNum = base.ModeIndex(chord);

	const int keyNum = Modalize::ToInt(key);
	const int roundNum = Modalize::Round(keyNum - 6);

	const auto circleOfFifth = Modalize::ToString(roundNum);

	const auto& dominantKey = ScaleDatabase::Find(circleOfFifth);
	
	return dominantKey.PrimaryMode(chordNum);
}