#include "DiatonicDatabase.hpp"
using namespace score::chord;

std::shared_ptr<DiatonicDatabase> DiatonicDatabase::_ptr = nullptr;

const DiatonicDatabase& DiatonicDatabase::GetInstance()
{
	if (_ptr == nullptr)
		_ptr = std::shared_ptr<DiatonicDatabase>(new DiatonicDatabase());
	return *_ptr;
}

const Chord& DiatonicDatabase::GetChord(const size_t index) const
{
	return major_diatonic[index];
}

const Chord& DiatonicDatabase::GetChord(const size_t index, const bool isMajor) const
{
	auto buf = index;
	if (!isMajor)
	{
		buf += 5;
		if (buf >= 7) buf -= 7;
	}
	return GetChord(buf);
}