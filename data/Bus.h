#pragma once
#include "Time_.h"

class Bus
{
	int num;
	Time_ start;
	Time_ stop;
	int length;
	int TimeRelax;


public:
	Bus();
	Bus(int num, Time_ start, Time_ stop, int length, int TimeRelax);

	void setnum(int num);
	int getnum()const;
	void setlength(int length);
	int getlength()const;
	void setTimeRelax(int TimeRelax);
	int getTimeRelax()const;


	void showInfo() const;


	friend ostream& operator << (ostream& out, const Bus& obj);
	friend istream& operator >> (istream& in, Bus& obj);
};