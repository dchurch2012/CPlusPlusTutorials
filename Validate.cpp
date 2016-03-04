#include "Validation.h"
#include <string>

using namespace std;

bool valid_double(string string_data)
{
	int length = string_data.length();
	unsigned int decCount = 0;

	for (int index = 0; index < length; index++)
	{
		if (isdigit(string_data[index]) || string_data[index] == '.')
		{
			if (string_data[index] == '.')
			{
				decCount++;

				if (decCount > 1)
					return false;
			}
		}
		else
			return false;
	}
	return true;
}

bool valid_integer(string string_data)
{
	int length = string_data.length();

	for (int index = 0; index < length; index++)
	{
		if (!isdigit(string_data[index]))
		{
			return false;
		}
	}
	return true;
}

bool validate_interest_rate(double rate)
{
	if (rate >= 0 && rate <= 1)
		return true;
	else
		return false;
}

