#include <stdlib.h>
#include "xml\tinyxml2.h"
#include "Chord.hpp"

void main()
{
	std::wstring str(L"C");
	const score::chord::ChordConstructions re;
	if (std::regex_match(str, re.roots[0].Regex()))
	{
		printf("test\n");
	}
	system("pause");
}