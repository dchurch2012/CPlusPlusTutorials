#pragma once

#include <string>
#include <vector>
#include "Stocks.h"

class StockQuoteContainer
{
public:
	std::vector<StockQuote> stocks;

	int AddQuote(StockQuote quote);
	double FindMaxHigh();
	double FindMinHigh();
	double FindMinLow();
	double FindMaxLow();

	double MovingAverageClose(int data_size,int span);
	double AverageClose(int begin, int end, int span);

};