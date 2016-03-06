#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <conio.h>

int WaitForEnd();

#define MAXCOL	4
#define MAXROW	3
#define MAX		4
#define MAX_MEM	512

int PointerDemo_003()
{	
	int y[6] = {1,2,3,4,5,6};    
	int index = 0;
    int i,k=1;
    int (*q)[MAX_MEM];      //pointer to an array of integers
	int  var[MAX] = {10, 100, 200, 145};
	int value = -1;

	//pointer to an array of integers
	int (*x)[6] = NULL;                 
	
	//Array of pointers TO integers
	int *ptr[MAX];

	x = &y;

	for(index = 0; index < sizeof(y) / sizeof(int); index++)
	{
		// This is the INCORRECT way of getting the contents of the array element
		// value = x[index]; 
		// This is ACTUALLY the address of x[0];
		printf("x[%d] address : %d\n", index, x[index]);
		
		printf("y array value : %d\n", y[index]);
		printf("x array value : %d\n", (*x)[index]);
	}

	q = (int (*)[MAX_MEM]) malloc(MAX_MEM * sizeof(int(*)[MAX_MEM]));
	
	for(i = 0; i < MAX_MEM; i++)
	{
		(*q)[i] = i;
		printf("%d\n",(*q)[i] );
	}

	for ( i = 0; i < MAX; i++)
	{
		ptr[i] = &var[i]; // assign the address of integer
	}
	
	for ( i = 0; i < MAX; i++)
	{
		printf("Value of var[%d] = %d\n", i, *ptr[i] );
	}

	return 0;
}

int WaitForEnd()
{
	printf("\n\nPress any key to terminate program");
		
	while(!_kbhit())
		;

	return 0;
}