#include <iostream>
#include <string>

#include "Tutorial004.h"

extern "C" int PointerDemo_001(); 
extern "C" int PointerDemo_002(); 
extern "C" int PointerDemo_003();
extern "C" char *PointerDemo_004();

using namespace std;

int main(int argc, char *argv[])
{
	int retval = PointerDemo_001();

	char *retString = PointerDemo_004();

	try
	{
		cout << retString << endl;
	}
	catch (char *szException)
	{
		cout << szException << " Raised" << endl;
	}


	retval = PointerDemo_002();
	retval = PointerDemo_003();
	

	return 0;
}