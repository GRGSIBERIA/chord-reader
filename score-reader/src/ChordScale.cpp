#include "ChordScale.hpp"
#include "KeyChordModalizer.hpp"
using namespace score::scale;

const ChordScale ChordScale::Mode(const int i) const 
{ 
	//return ChordScale(chord, scaleIndex, i, modes[(size_t)i], availables[(size_t)i], modes, availables, modalizer); 
	return modalizer.Mode(scaleIndex, i);
}