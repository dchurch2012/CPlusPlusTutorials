#pragma once

#include <string>

using namespace std;

class StockQuote
{
protected:
	string Date;
	double Open;
	double High;
	double Low;
	double Close;
	double Volume;
	double AdjClose;

public:
	void setDate(string _Date)
	{
		Date = _Date;
	}
	
	string getDate()
	{
		return Date;
	}
	
	void setOpen(double _Open)
	{
		Open = _Open;
	}
	
	double getOpen()
	{
		return Open;
	}


	void setHigh(double _High)
	{
		High = _High;
	}
	
	double getHigh()
	{
		return High;
	}
	
	void setLow(double _Low)
	{
		Low = _Low;
	}
	
	double getLow()
	{
		return Low;
	}
	
	void setClose(double _Close)
	{
		Close = _Close;
	}

	double getClose()
	{
		return Close;
	}

void setVolume(double _Volume)
	{
		Volume = _Volume;
	}
	
	double getVolume()
	{
		return Volume;
	}
	
	void setAdjClose(double _AdjClose)
	{
		AdjClose = _AdjClose;
	}
	
	double getAdjClose()
	{
		return AdjClose;
	}
	
};
