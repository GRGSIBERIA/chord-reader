#include "DiatonicDatabase.hpp"
using namespace score::chord;

std::shared_ptr<DiatonicDatabase> DiatonicDatabase::_ptr = nullptr;

const DiatonicDatabase& DiatonicDatabase::GetInstance()
{
	if (_ptr == nullptr)
		_ptr = std::shared_ptr<DiatonicDatabase>(new DiatonicDatabase());
	return *_ptr;
}