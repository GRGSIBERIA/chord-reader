#include <stdlib.h>
#include "xml\tinyxml2.h"

void main()
{
	tinyxml2::XMLDocument doc;

	auto error = doc.LoadFile("./chord-reader/resources/autumun leaves.xml");
	if (error == tinyxml2::XMLError::XML_SUCCESS)
	{
		printf("hoge\n");
	}
	system("pause");
}