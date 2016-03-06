#include <iostream>

#include "Average.h"
#include "StockQuoteContainer.h"

#include <cstdlib>
#include <fstream>
#include <string>

#include "Stats.h"

using namespace std;

void read_data(string instring);
void getQuotes(StockQuoteContainer& stock_container, char *filename);
void Fileread(char *filename);
double ComputePi(int ndigits);

int main(int argc, char *argv[])
{
	cout << "Arg count" << argc << endl;
	
	for (int index = 0; index < argc; index++)
	{
		cout << argv[index] << endl;
	}

	if (argc < 2)
	{
		cout << "Usage : " << endl;
		cout << "1 for Average Function" << endl;
		cout << "2 for Stock Quote CSV File Demo -- argv[2] = filename input" << endl;
		cout << "3 for For Loop Demo to calculate PI" << endl;
		cout << "4 for Covariance, Vector and Class Demo" << endl;

		return -1;

	}
	int decision = atoi(argv[1]);
	StockQuoteContainer stock_container;
	Stats stats;
	double pi = 0;
	int err = 0;
	double average = 0;
	double cov = 0;

	system("cls");

	switch (decision)
	{
		case 1:
			//Demonstrates Averaging
			//Demonstrates While Loop
			//Demonstrates IF THEN LOGIC
			cout << "Demonstrating Average Method" << endl;
			AverageString();
			break;

		case 2:
			cout << "Demonstrating Stock Quote Processing from CSV File" << endl;
			getQuotes(stock_container,argv[2]);
			break;

		case 3:
			cout << "Demonstrating for loop - calculete PI" << endl;
			pi = ComputePi(670000);

			std::cout.precision(12);
			cout << pi << endl;
			break;
		
		case 4:
			cout << "Demonstrating Covariance" << endl;

			stats.EnterVar1Data();
			average = stats.AverageDataSet1(err);

			cout << "Average data_set 1 is :" << average << endl;

			stats.EnterVar2Data();
			average = stats.AverageDataSet2(err);

			cout << "Average data_set 1 is :" << average << endl;

			cov = stats.Covariance();
			cout << "Covariance is :" << cov << endl;
			break;

		default:
			break;
	}

	system("PAUSE");
	return 0;
}

void Fileread(char *filename)
{
	ifstream infile(filename);
	string instring;

	while (!infile.eof())
	{
		infile >> instring;
		cout << instring << endl;
	}

	infile.close();
}

void getQuotes(StockQuoteContainer& stock_container, char *filename)
{
	// Date, Ticker, Open, High, Low, Close, Volume for the day
	char *pch = NULL;
	int index = 0;
	char szData[512];
	ifstream infile;
	string instring;

	int count = 0;
	
	infile.open(filename, ios::in);

	if (!infile) {
		cerr << "Can't open input file " << filename << endl;
		return;
	}

	while (!infile.eof())
	{
		StockQuote stock;
		index = 0;
		char *context = NULL;

		infile >> instring;
		cout << instring << endl;

		if (count < 2)
		{
			count++;
			continue;
		}

		//infile.getline(szData,sizeof(szData));
		pch = strtok_s((char *)instring.c_str(), ",",&context);

		//Date	Open	High	Low	Close	Volume	Adj Close*
		while (pch != NULL)
		{
			switch (index)
			{
			case 0:
				stock.setDate(pch);
				break;

			case 1:
				stock.setOpen(atof(pch));
				break;

			case 2:
				stock.setHigh(atof(pch));
				break;

			case 3:
				stock.setLow(atof(pch));
				break;

			case 4:
				stock.setClose(atof(pch));
				break;

			case 5:
				stock.setVolume(atof(pch));
				break;

			case 6:
				stock.setAdjClose(atof(pch));
				break;
			}
			pch = strtok_s(NULL, ",",&context);
			index++;
		}
		stock_container.AddQuote(stock);
	}

	infile.close();

}

double ComputePi(int ndigits)
{
	double sum = 0;
	double intermediate = 0;
	//(-1) ^ n / [2n + 1]

	for (int index = 0; index < ndigits; index++)
	{
		intermediate = pow(-1, index) / (2*index + 1);
		sum = sum + intermediate;
	}

	return sum * 4;
}
void Tokenizer()
{
	char* context = NULL;
	char str[] = "- This, a sample string.";
	char * pch;
	printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok_s(str, " ,.-", &context);
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok_s(NULL, " ,.-", &context);
	}
}