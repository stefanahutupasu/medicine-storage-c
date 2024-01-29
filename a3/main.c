#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <crtdbg.h>
#include "ui.h"
#include "tests.h"

int main()
{
	testsA3();
	run();

	_CrtDumpMemoryLeaks();

	return 0;
}