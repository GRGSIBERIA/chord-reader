#include "gtest/gtest.h"

#pragma comment( lib, "gtest.lib" )
#pragma comment( lib, "gtest_main.lib" )

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	auto r = RUN_ALL_TESTS();
	system("pause");
	return r;
}