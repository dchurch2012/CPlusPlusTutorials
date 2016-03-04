#include <iostream>

using namespace std;

bool IsDigit(char);

int main(int argc, char *argv[])
{
	string a = "1234AA";
	string b = "834";
	bool valid = true;
	int index = 0;

	int length = a.length();

	for (index = 0; index < length; index++)
	{
		if (!IsDigit(a[index]))
		{
			valid = false;
		}
	}

	if (valid)
	{
		cout << "valid number string" << endl;
	}
	else
	{
		cout << "Invalid number string" << endl;
	}

	/////////////////////////////////////////////////////////////////////////////
	//VALID STRING
	/////////////////////////////////////////////////////////////////////////////
	length = b.length();
	valid = true;

	for (index = 0; index < length; index++)
	{
		if (!IsDigit(b[index]))
		{
			valid = false;
		}
	}

	if (valid)
	{
		cout << "valid number string" << endl;
	}
	else
	{
		cout << "Invalid number string" << endl;
	}
	return 0;
}

bool IsDigit(char in_char)
{
	string LookupTable = { '0','1','2','3','4','5','6','7','8','9' };

	int length = LookupTable.length();

	for (int index = 0; index < length; index++)
	{
		if (in_char == LookupTable[index])
			return true;
	}

	return false;
}