#include "Modal.hpp"
#include <exception>
using namespace score::scale;

const std::array<std::wstring, 12> Modalize::sharp = { L"C", L"C#", L"D", L"D#", L"E", L"F", L"F#", L"G", L"G#", L"A", L"A#", L"B" };
const std::array<std::wstring, 12> Modalize::flat = { L"C", L"Db", L"D", L"Eb", L"E", L"F", L"Gb", L"G", L"Ab", L"A", L"Bb", L"B" };

const int Modalize::HasAccidental(const std::wstring& str)
{
	if (str[1] == L'b')
		return -1;
	else if (str[1] == L'#')
		return 1;
	return 0;
}
const Modal Modalize::ToModal(const int& modal) 
{ 
	return (Modal)modal; 
}
const int Modalize::ToInt(const Modal& modal) 
{ 
	return (int)modal; 
}
const std::wstring& Modalize::ToString(const Modal modal, const bool isSharp)
{
	return ToString((int)modal, isSharp);
}
const std::wstring& Modalize::ToString(const int modal, const bool isSharp)
{
	if (isSharp)
		return sharp[modal];
	return flat[modal];
}
int RootToInt(const std::wstring& str)
{
#define IFSTR(X, N) if (str[0] == X) { return N; }
	IFSTR(L'C', 0);
	IFSTR(L'D', 2);
	IFSTR(L'E', 4);
	IFSTR(L'F', 5);
	IFSTR(L'G', 7);
	IFSTR(L'A', 9);
	IFSTR(L'B', 11);
#undef IFSTR
	throw std::invalid_argument("Unrecognized root name");
}
const int Modalize::ToInt(const std::wstring& str)
{
	return RootToInt(str) + HasAccidental(str);
}
const Modal Modalize::ToModal(const std::wstring& str)
{
	return (Modal)ToInt(str);
}
const bool Modalize::HasMinor(const std::wstring& str)
{
	return str.find(L'm') != std::wstring::npos;
}
const bool Modalize::HasMajor(const std::wstring& str)
{
	return str.find(L'm') == std::wstring::npos;
}
const int Modalize::Round(const int modal)
{
	if (modal > 11)
		return Round(modal - 12);
	else if (modal < 0)
		return Round(modal + 12);
	return modal;
}