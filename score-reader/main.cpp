#include <stdlib.h>
#include "xml\tinyxml2.h"
#include "score\Chord.hpp"

void main()
{
	tinyxml2::XMLDocument doc;
	score::Chord chord(L"");

	auto error = doc.LoadFile("autumn leaves.xml");
	if (error == tinyxml2::XMLError::XML_SUCCESS)
	{
		printf("hogaoeue\n");
	}
	system("pause");
}