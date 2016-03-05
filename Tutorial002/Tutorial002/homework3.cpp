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

using namespace std;

int main(int argc, char *argv[])
{
	double initialDepositAmount = 0;
	double annualInterestRate = 0;
	double yearsInvested = 0;
	int periodPerYear = 0;
	double futureValue = 0;
	string input_data =  "";

	cout << "Enter the initial deposit amount                : ";
	getline(cin, input_data);

	if (valid_double(input_data))
	{
		initialDepositAmount = atof(input_data.c_str());
	}

	cout << "Please enter Annual Interest Rate in percentage : ";
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
	//ADD CODE HERE...

	cout << "Enter Number of years before withdrawl          : ";
	//ADD CODE HERE...

	//ADD CODE HERE...(futureValue calculation)

	return 0;
}