#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <conio.h>

int PointerDemo_002()
{
	int this_var = -1233;

	printf("This program demonstrates scoping and local (stack) variables\n\n");
	printf("First this_Var value : %d\n", this_var);
	
	{
		int this_var = 13298;
		printf("Second this_Var value : %d\n", this_var);
		{
			int this_var = 67344;
			printf("Third this_Var value : %d\n", this_var);
		}

	}

	printf("The first value again -- still in memory unchanged : %d\n", this_var);
	
	printf("\n\nPress any key to terminate program");
		
	while(!_kbhit())
		;
	return 0;
}

