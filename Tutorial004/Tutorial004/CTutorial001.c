#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <conio.h>
#include <memory.h>

#define _CRT_SECURE_NO_WARNINGS
		
int PointerDemo_001()
{
	char in_char = '\0';
	char *str_data = NULL;
	int char_count = 1;	//At least one for null terminator
	int index = 0;
	char *temp = NULL;
	
	//Alocate storage for 2 characters - initial character and null terminator
	str_data = malloc(sizeof(char) * 2);
	
	//Initialize memory to all 0s (null terminator)
	memset((char *) str_data, '\0', sizeof(char) * 2);	

	printf("Enter a string of characters; Press 'Enter' to terminate : ");

	//Until user presses Enter Key
	while(in_char != '\r')
	{
		//Get a single character from the character 
		in_char = _getche();
	
		//update character count
		char_count++;
	
		//check for ENTER key press
		if(in_char == '\r')
		{
			//Make sure very last character is NULL terminator
			str_data[index] = '\0';
			
			// force another (while) execution - which will fail since inchar = ENTER Key
			continue;
		}

		// Concatenate memory with one more characater for NEW character -- Note this
		// call preserves our original data (the chars we added are saved)
		temp = (char *)realloc(str_data, sizeof(char) * char_count);
		
		if (temp != NULL)
		{
			str_data = temp;
		}
		//Set next char = key entered by user
		str_data[index] = in_char;
		
		//bump up index for next char
		index++;
	}

	//String is ready to be printed
	printf("\n\nYou Entered : %s\n", str_data);

	printf("\n\nPress any key to end program");

	//Loops until user presses ANY key - so user can view output before program
	// terminates
	while(!_kbhit())
		;

	return 0;		
}


