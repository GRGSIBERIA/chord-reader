#include "Modal.hpp"
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