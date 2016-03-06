//#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "StockQuoteContainer.h"

struct MaxHigh
{
    bool operator()( StockQuote& lx, StockQuote& rx ) const {
    	return lx.getHigh() < rx.getHigh();
    }
};

struct MinHigh
{
    bool operator()( StockQuote& lx, StockQuote& rx ) const {
    	return lx.getHigh() > rx.getHigh();
    }
};

struct MinLow
{
    bool operator()( StockQuote& lx, StockQuote& rx ) const {
    	return lx.getLow() > rx.getLow();
    }
};

struct MaxLow
{
    bool operator()( StockQuote& lx, StockQuote& rx ) const {
    	return lx.getLow() < rx.getLow();
    }
};

int StockQuoteContainer::AddQuote(StockQuote quote)
{
	stocks.push_back(quote);
	return 0;
}

double StockQuoteContainer::FindMaxHigh()
{
	std::sort(stocks.begin(), stocks.end(),MaxHigh());
	int count = stocks.size(); 
	double max_high = stocks[count-1].getHigh();

	return max_high;
}

double StockQuoteContainer::FindMinHigh()
{
	std::sort(stocks.begin(), stocks.end(),MinHigh());
	int count = stocks.size(); 
	double min_high = stocks[count-1].getHigh();

	return min_high;
}

double StockQuoteContainer::FindMinLow()
{
	std::sort(stocks.begin(), stocks.end(),MinLow());
	int count = stocks.size(); 
	double min_low = stocks[count-1].getLow();

	return min_low;
}

double StockQuoteContainer::FindMaxLow()
{
	std::sort(stocks.begin(), stocks.end(),MaxLow());
	int count = stocks.size(); 
	double max_low = stocks[count-1].getLow();

	return max_low;
}

double StockQuoteContainer::AverageClose(int begin,int end, int span)
{
	double sum = 0;
	double count = 0;
	double average = 0;

	if(end < stocks.size())
	{
		for(int index = begin; index < end; index++)
		{
			sum = sum + stocks[index].getClose();
			count++;
		}
	}

	average = sum / count;
	return average;
}

double StockQuoteContainer::MovingAverageClose(int data_size, int span)
{
	int count = stocks.size(); 
	int sub_count = 0;
	double sum = 0;
	double average = 0;
	int begin = 0;
	int end = 0;
	bool done = false;
	
	while(!done)
	{
		end = begin + data_size;

		if(end < count)
		{
			average = AverageClose(begin,end,span);
			sum = sum + average;
			begin += span;
			sub_count++;
		}
		else
		{
			done = true;
			continue;
		}
	}

	average = sum / sub_count;
	return average;
}
