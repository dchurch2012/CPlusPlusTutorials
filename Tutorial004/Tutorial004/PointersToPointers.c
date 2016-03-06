#include <stdlib.h>
#include <stddef.h >
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define _CRT_SECURE_NO_WARNINGS

int FunctionDemo_003()
{
	char **array = NULL;
	char **start = NULL;
	char *ptrstart = NULL;
	int done = 0;
	int count = 0;
	int nval = 0;
	int index = 10;
	int string_size = 64;
	char szBuffer[64];

	while(!done)
	{
		//Allocation: 1 pointer to a pointer -- not nearly enough for
		//what we WILL need -- but we are going to keep reallocating as we go
		
		//NOTE: start is null to begin with; this is OK -- realloc KNOWS this
		//and will "work it out" accordingly
		array = (char **) realloc(start, (count + 1) * sizeof(char *));
		
		//Now that array has been allocated, start can be pointed to it
		start = array;

		//Now comes the beginning of useful memory
		//The base pointer has been allocated
		//ptr = &ptr[0]
		//This was done by the realloc.
		//Now, we are going to allocate memory for ptr[0]
		//This is the actual storage for our string
		array[count] = (char * )malloc(string_size * sizeof(char));
		
		//Initialize memory to all zeroes
		memset((char *)array[count], '\0', string_size);
	
		//Initialize the array pointer ptrstart
		ptrstart = array[count];

		printf("Enter a string : ");
		gets(szBuffer);
		
		//Check for empty string in szBuffer
		//If empty ==> we are done
		//continue is there to force another loop "go around"
		
		if(!strcmp(szBuffer,""))
		{
			done = 1;
			continue;
		}

		if(array[count] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			return -2;
		}

		strcpy(array[count], szBuffer);
		count++;
	}

	for(index = 0; index < count-1; index++)
	{
		printf("%d",array[index]);
		printf("\n");
	}

	printf("Press any key to end program");
	
	while(!_kbhit())
		;

	//The program terminates -- we have just dynamically
	//allocated strings without knowing ahead of time (at compile time)
	//how many strings would be entered
	return 0;
}

