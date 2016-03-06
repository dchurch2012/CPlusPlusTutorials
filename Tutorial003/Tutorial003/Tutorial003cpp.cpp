#include <iostream>

using namespace std;

int AsciiToInteger(char *num_string);
double AsciiToFloat(char *num_string);

int main(int argc, char *argv[])
{
	char *input = "2345";
	double ret = AsciiToInteger(input);

	cout << "Numeric value of " << "\"" << input << "\" " << ret << endl;

	char *data = "345.124";
	ret = AsciiToFloat(data);

	cout << "Numeric value of " << "\"" << data << "\" " <<  ret << endl;

	return 0;

}

int AsciiToInteger(char *num_string)
{
	int length = strlen(num_string);
	int accum = 0;

	for (int index = 0; index < length; index++)
	{
		accum += ((int)num_string[index] - 48) * pow(10,(length-index-1));
	}
	return accum;
}

double AsciiToFloat(char *num_string)
{
	int length = strlen(num_string);
	double accum = 0;
	bool decimal = false;
	int power = 1;
	int loc_decimal = 0;

	for (int index = 0; index < length; index++)
	{
		if (num_string[index] == '.')
			loc_decimal = index;
	}

	for (int index = 0; index < length; index++)
	{
		if (num_string[index] == '.')
		{
			index++;
			decimal = true;
		}

		if (decimal == false)
		{
			accum += ((int)num_string[index] - 48) * pow(10, (loc_decimal - index - 1));
		}
		else
		{
			accum += ((int)num_string[index] - 48) * pow(10, -(power++));
		}
	}
	return accum;
}