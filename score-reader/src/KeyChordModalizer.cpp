#include "KeyChordModalizer.hpp"
using namespace score::scale;

KeyChordModalizer::KeyChordModalizer(const Modal& key, const bool isMajor)
	: mode(Scale(Modalize::ToString(key) + (isMajor ? L"" : L"m"), scale.GetScale(key)), { 0, 2, 4, 6 })
{

}