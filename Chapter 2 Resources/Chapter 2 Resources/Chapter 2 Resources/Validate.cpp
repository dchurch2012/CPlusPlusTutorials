#include <cstdlib>

#include <ctype.h>
#include <iostream>
#include <iomanip>

#include <iostream>
#include <string>

using namespace std;

int AverageString();
int Average();

double compute_average(double,unsigned int);

using namespace std;

int Demo()
{
    cout << "This average uses a 'C' type string for input" << endl;
    Average();

    cout << "This average uses a 'C++' type string for input" << endl;
    AverageString();

    system("PAUSE");
    return EXIT_SUCCESS;
}

bool ValidateData(char *szData, double& dblGrade)
{
	size_t nLength = strlen(szData);
	unsigned int decCount = 0;

	for(unsigned int index = 0; index < (static_cast<unsigned int>(nLength)); index++)
	{
		if(isdigit(szData[index]) || szData[index] == '.')
		{
			if(szData[index] == '.')
			{
				decCount++;
			
				if(decCount > 1)
					return false;
			}
		}
		else
			return false;
	}

	dblGrade = atof(szData);
	return true;
}

bool ValidateDataString(string strData, double& dblGrade)
{
	size_t nLength = strData.length();
	unsigned int decCount = 0;

	for(unsigned int index = 0; index < (static_cast<unsigned int>(nLength)); index++)
	{
		if(isdigit(strData[index]) || strData[index] == '.')
		{
			if(strData[index] == '.')
			{
				decCount++;
			
				if(decCount > 1)
					return false;
			}
		}
		else
			return false;
	}

	dblGrade = atof(strData.c_str());

	return true;
}


