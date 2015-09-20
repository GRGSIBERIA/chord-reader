#include "Modal.hpp"
#include <exception>
using namespace score::scale;

const std::array<std::wstring, 12> Modalize::sharp = { L"C", L"C#", L"D", L"D#", L"E", L"F", L"F#", L"G", L"G#", L"A", L"A#", L"B" };
const std::array<std::wstring, 12> Modalize::flat = { L"C", L"Db", L"D", L"Eb", L"E", L"F", L"Gb", L"G", L"Ab", L"A", L"Bb", L"B" };

Modal Modalize::ToModal(const int& modal) 
{ 
	return (Modal)modal; 
}
int Modalize::ToInt(const Modal& modal) 
{ 
	return (int)modal; 
}
const std::wstring& Modalize::ToString(const Modal& modal, const bool isSharp = true)
{
	return ToString((int)modal, isSharp);
}
const std::wstring& Modalize::ToString(const int& modal, const bool isSharp = true)
{
	if (isSharp)
		return sharp[modal];
	return flat[modal];
}
int RootToInt(const std::wstring& str)
{
#define IFSTR(X, N) if (str[0] == L'X') { return N; }
	IFSTR(C, 0);
	IFSTR(D, 2);
	IFSTR(E, 4);
	IFSTR(F, 5);
	IFSTR(G, 7);
	IFSTR(A, 9);
	IFSTR(B, 11);
#undef IFSTR
	throw std::invalid_argument("Unrecognized root name");
}
int Modalize::ToInt(const std::wstring& str)
{
	int num = RootToInt(str);
	if (str[1] == L'b')
		--num;
	else if (str[1] == L'#')
		++num;
	return num;
}
Modal Modalize::ToModal(const std::wstring& str)
{
	return (Modal)ToInt(str);
}