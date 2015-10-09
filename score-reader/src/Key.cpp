#include "Key.hpp"
using namespace score::scale;

int Round(int num)
{
	if (num > 11) num -= 12;
	return num;
}
std::wstring SwapMinor(const std::wstring& str)
{
	return !Modalize::HasMinor(str) ? L"m" : L"";
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
const std::wstring CalcUnder(const std::wstring& str, int maj, int min)
{
	if (!Modalize::HasMinor(str))
	{
		auto num = Round(Modalize::ToInt(str) + maj);
		return Modalize::ToString(num) + SwapMinor(str);
	}
	else
	{
		auto num = Round(Modalize::ToInt(str) + min);
		return Modalize::ToString(num) + SwapMinor(str);
	}
}

const std::wstring Key::Parallel(const std::wstring& str)
{
	auto num = Modalize::ToInt(str);
	return Modalize::ToString(num) + SwapMinor(str);
}
const std::wstring Key::Relative(const std::wstring& str)
{
	return CalcUnder(str, 9, 4);
}
const std::wstring Key::Dominant(const std::wstring& str)
{
	return CalcTop(str, 7);
}
const std::wstring Key::SubDominant(const std::wstring& str)
{
	return CalcTop(str, 5);
}
const std::wstring MinorDominant(const std::wstring& str)
{
	return CalcUnder(str, 4, 11);
}
const std::wstring MinorSubDominant(const std::wstring& str)
{
	return CalcUnder(str, 5, 9);
}