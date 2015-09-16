#include "ModeTheory.hpp"
using namespace score::scale;

ModeTheory::ModeTheory(const Scale& scale)
{
	modeScales[0] = scale;

	for (size_t i = 1; i < modeScales.size(); ++i)
	{
		for (int cnt = 0; cnt < modeScales.size(); ++cnt)
		{

		}
	}
}