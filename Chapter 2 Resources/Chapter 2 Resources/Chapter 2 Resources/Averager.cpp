#include <cstdlib>

#include <ctype.h>
#include <iostream>
#include <iomanip>

#include <iostream>
#include <string>

#include "Validate.h"

#include "Average.h"

using namespace std;

int AverageString();
int Average();

#define MAX_LEN				256
#define	MAX_NUM				64

#define MESSAGE				"Enter a Number : "
#define AVERAGE_MESSAGE		"Average Is     : "
#define	MESSAGE_WIDTH		30

int Average()
{
	char szData[MAX_LEN];
	double accumulator = 0;
	double dblGrade = 0;
	double dblAverage = 0;
	unsigned int count = 0;

	memset(szData, '\b', sizeof(szData));

	while (strcmp(szData, ""))
	{
		cout << setw(MESSAGE_WIDTH) << left << MESSAGE;
		cin.getline(szData, sizeof(szData));

		if (strcmp(szData, ""))
		{
			if (!ValidateData(szData, dblGrade))
			{
				cout << "Data must be numeric" << endl;
			}
			else
				if (strcmp(szData, ""))
				{
					count++;
					accumulator += dblGrade;
				}
		}
	}

	if (count != 0)
	{
		dblAverage = compute_average(accumulator, count);
		cout << setw(MESSAGE_WIDTH) << AVERAGE_MESSAGE << dblAverage << endl << endl;
	}
	else
	{
		cout << "No data Entered - no data to average" << endl << endl;
	}
	return 0;
}

int AverageString()
{
	string strData = "|";
	double accumulator = 0;
	double dblValue = 0;
	double dblAverage = 0;
	unsigned int count = 0;

	while (strData != "")
	{
		cout << setw(MESSAGE_WIDTH) << left << MESSAGE;
		getline(cin, strData);

		if (strData != "")
		{
			if (!ValidateDataString(strData, dblValue))
			{
				cout << "Data must be numeric" << endl;
			}
			else
				if (strData == strData)
				{
					count++;
					accumulator += dblValue;
				}
		}
	}

	if (count != 0)
	{
		dblAverage = compute_average(accumulator, count);
		cout << setw(MESSAGE_WIDTH) << AVERAGE_MESSAGE << dblAverage << endl << endl;
	}
	else
	{
		cout << "No data Entered - no numbers to average" << endl << endl;
	}
	return 0;
}

double compute_average(double dblSum, unsigned int count)
{
	double dblAverage = dblSum / (double)count;
	return dblAverage;
}

