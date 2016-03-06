#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Validate.h"

class Stats
{
protected:
	vector<double> data_set[2];
	double data_set1_average;
	double data_set2_average;

public:
	Stats()
	{
		data_set[0];
		data_set[1];
	}

	double Covariance();
	int EnterVar1Data();
	int EnterVar2Data();

	double AverageDataSet1(int&);
	double AverageDataSet2(int&);

};
