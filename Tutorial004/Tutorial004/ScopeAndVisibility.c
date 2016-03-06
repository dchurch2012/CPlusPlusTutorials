#include <stdlib.h>
#include <stddef.h >
#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "Tutorial004.h"


int fun(char *szString);
char *fun2();
char *fun3();
char *fun4();
char *fun5(char *szIn);

char *PointerDemo_004()
{
	char *szMessage = "This is declared in thePointerDemo_004 routine\n";

	fun(szMessage);

	szMessage = fun2();

	//!!!BUG!!!
	//Check the fun2 declaration.
	//The string declared in fun2 GOES AWAY
	//when the function exits -- because it is stored
	//on the stack and that stack space is no longer 
	//in use -- it MAY run OK; BUT: It really is a bug
	//that will cause a crash if the string is BIG enough.

	printf(szMessage);

	szMessage = fun3();

	szMessage = fun4();
	szMessage = fun5(szMessage);
	
	//The program terminates -- we have just dynamically
	//allocated strings without knowing ahead of time (at compile time)
	//how many strings would be entered
	szMessage = "STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK|STACK";
	return szMessage;
}

int fun(char *szString)
{
	printf("This message is printed inside fun : \n");
	printf(szString);
	return 0;
}

char *fun2()
{
	char *szMessage = "This fun2() call is going to crash when the string is used from outside fun2()\n\n";
	printf(szMessage);
	return szMessage;
}

char *fun3()
{
	static char *szMessage = "This fun3() call is fine because a STATIC var is stored in _BSS Group - available during the life of the program -- but you can only SEE it here!!!\n\n";

	printf(szMessage);
	return szMessage;
}

char *fun4()
{
	char *szMessage = (char *)malloc(128 * sizeof(char));
	
	strcpy(szMessage,"This fun4() call is fine because szMessage was allocaated in the HEAP and only a free of this var will eliminate it\n\n");
	printf(szMessage);
	return szMessage;
}

char *fun5(char *szIn)
{
	printf("fun5 works because szIn was passed in by an external routine\n");
	printf(szIn);
	printf("BUT: Be careful if you overwrite it, make sure there is sufficient space\n");
	printf("Use strlen to check\n\n");

	return szIn;
}
