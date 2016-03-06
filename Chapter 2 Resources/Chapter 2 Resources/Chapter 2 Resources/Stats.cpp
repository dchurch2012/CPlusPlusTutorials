#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Validate.h"

#include "Stats.h"

using namespace std;

double Stats::Covariance()
{
	int count1 = data_set[0].size();
	int count2 = data_set[1].size();
	int count = 0;
	double diff1 = 0;
	double diff2 = 0;
	double covariance = 0;

	if (count1 > count2)
	{
		count = count2;
	}
	else
	{
		count = count1;
	}
	
	vector<double> temp1;
	vector<double> temp2;
	double sum1 = 0;
	double sum2 = 0;
	double prod = 0;

	for (int index = 0; index < count; index++)
	{
		double d1 = (data_set[0][index] - data_set1_average);
		double d2 = (data_set[1][index] - data_set2_average);

		temp1.push_back(d1);
		temp2.push_back(d2);
	}

	for (int jindex = 0; jindex < count; jindex++)
	{
		prod = prod + (temp1[jindex] * temp2[jindex]);

	}

	covariance = prod / ((double)count - 1);

	return covariance;
}

int Stats::EnterVar1Data()
{
	string data = "|";
	double dblValue = 0;

	while (data != "")
	{
		cout << "Enter a data point ";
		getline(cin,data);

		if (data == "")
		{
			continue;
		}

		if (!ValidateDataString(data, dblValue))
		{
			cout << "Please enter a numeric value" << endl;
			continue;
		}
		else
		{
			data_set[0].push_back(dblValue);
		}

	}
	return 0;
}

int Stats::EnterVar2Data()
{
	string data = "|";
	double dblValue = 0;

	while (data != "")
	{
		cout << "Enter a data point ";
		getline(cin, data);

		if (data == "")
		{
			continue;
		}

		if (!ValidateDataString(data, dblValue))
		{
			cout << "Please enter a numeric value" << endl;
			continue;
		}
		else
		{
			data_set[1].push_back(dblValue);
		}

	}
	return 0;
}

double Stats::AverageDataSet1(int &error)
{
	int count = data_set[0].size();
	double sum = 0;
	double average = 0;

	if (count == 0)
	{
		error = -1;
		return -1;
	}

	for (int index = 0; index < count; index++)
	{
		sum = sum + data_set[0][index];
	}

	average = sum / count;
	error = 0;

	data_set1_average = average;

	return average;
}

double Stats::AverageDataSet2(int &error)
{
	int count = data_set[1].size();
	double sum = 0;
	double average = 0;

	if (count == 0)
	{
		error = -1;
		return -1;
	}

	for (int index = 0; index < count; index++)
	{
		sum = sum + data_set[1][index];
	}

	average = sum / count;
	error = 0;

	data_set2_average = average;
	
	return average;
}