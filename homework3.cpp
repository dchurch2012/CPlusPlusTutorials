#include <cstdlib>
#include <iostream>
#include <memory>
#include <iomanip>
#include <string.h>
#include <ctype.h>
#include <cmath>

#include "Validation.h"

#define	INTEREST_RATE_FORMAT_ERROR				-1
#define	DEPOSIT_AMOUNT_RATE_FORMAT_ERROR		-2
#define	COMPOUNDING_VALUE_FORMAT_ERROR			-3
#define	YEARS_UNTIL_WITHDRAWL_FORMAT_ERROR		-4
#define	FUTURE_VALUE_FORMAT_ERROR				-5

#define	INVALID_INTEREST_RATE_STRING			"Invalid interest rate must be numeric between 0 and 100"
#define INTEREST_RATE_FORMAT_ERROR_STRING		"Error in data format for Annual Interest Rate - must be numeric value" 
#define COMPOUNDING_VALUE_FORMAT_ERROR_STRING	"Error in data format for number of comounding periods - must be numeric between 0 and 12" << endl;
#define	YEARS_UNTIL_WITHDRAWL_ERROR_STRING		"Error in data format for years until withdrawl - must be numeric value"

//Author: Jacob Myerly
//Date: 2 March 2016
//Program: Compund interest calculator.
//Features: Dynamically allocated memory, error checking. 
//Author's Notes: Comments located throughout the code are intended to inform and instruct. 
//If you have any questions about the content of this program, or its 
//structure, please contact me.

// 1. Need to validate each entry individually.
// 2. Need to correct and validate annualInterestRate to allow for percentages
// 3. Need to set decimal places on totalPlusInterest
// 4. Need to figure out how to properly do header files.


using namespace std;

int main(int argc, char *argv[])
{
	//This is the dynamically allocated memory structure. Instead of
	//initializing variables and worrying about how large they are later,
	//I dynamically allocated them. This means that they will only take up the
	//precise space in memory that they need, when they are needed. As soon as they
	//are not needed, they will be destroyed and the memory will be freed up for other
	//things. This should help the program run faster and more efficiently. 

	double initialDepositAmount = 0;
	double annualInterestRate = 0;
	double yearsInvested = 0;
	double totalPlusInterest = 0;
	int periodPerYear = 0;
	double futureValue = 0;
	string input_data =  "";

	//Get all the data from user.
	//I'm considering putting this portion into some sort of function and just calling it.
	
	cout << "Please enter Annual Interest Rate in percentage : " << endl;
	getline(cin, input_data);
	
	if(valid_double(input_data))
	{
		annualInterestRate = atof(input_data.c_str());
	
		//Divide percentage value by 100 to obtain value between 0 and 1
		annualInterestRate /= 100;
	
		if (!validate_interest_rate(annualInterestRate))
		{
			cout << INVALID_INTEREST_RATE_STRING << endl;
		}
	}
	else
	{
		cout << INTEREST_RATE_FORMAT_ERROR_STRING;
		return INTEREST_RATE_FORMAT_ERROR;
	}

	cout << "How many compounding periods per year           : ";
	if (valid_integer(input_data))
	{
		periodPerYear = atoi(input_data.c_str());
	}
	else
	{
		cout << COMPOUNDING_VALUE_FORMAT_ERROR_STRING;
		return COMPOUNDING_VALUE_FORMAT_ERROR;
	}

	cout << "Enter Number of years nefore withdrawl          :";
	if (valid_integer(input_data))
	{
		yearsInvested = atoi(input_data.c_str());
	}
	else
	{
		cout << YEARS_UNTIL_WITHDRAWL_ERROR_STRING;
		return YEARS_UNTIL_WITHDRAWL_FORMAT_ERROR;
	}

	/*------------------------------------------------------
	 * Jacob : Modify Code here to reflect pattern above
	 *------------------------------------------------------
	 */

	cout << "Enter the initial deposit amount                : ";
	//cin >> *initialDepositAmount;

	//cout << endl;
	//cin >> *yearsInvested;

	//This "works", but I would appreciate a double check just to make sure.
	//*totalPlusInterest = *initialDepositAmount*pow((1 + *annualInterestRate / *periodPerYear), (*periodPerYear**yearsInvested));
	futureValue = initialDepositAmount * pow((1 + annualInterestRate / periodPerYear), periodPerYear * yearsInvested);

	//Display information to user
	//cout << *totalPlusInterest << endl;

	return 0;
}