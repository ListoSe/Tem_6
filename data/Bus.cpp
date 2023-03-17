#include "Bus.h"

Bus::Bus()
{
	num = 0;
	start = Time_(6, 0, 0);
	stop = Time_(21, 0, 0);
	length = 0;
	TimeRelax = 0;
}

Bus::Bus(int num, Time_ start, Time_ stop, int length, int TimeRelax)
{
	this->num = num;
	this->start = start;
	this->stop = stop;
	this->length = length;
	this->TimeRelax = TimeRelax;
}

void Bus::setnum(int num)
{
	if (num >= 0)
	{
		this->num = num;
	}
}

int Bus::getnum() const
{
	return num;
}

void Bus::setlength(int length)
{
	if (length >= 0)
	{
		this->length = length;
	}
}

int Bus::getlength() const
{
	return length;
}

void Bus::setTimeRelax(int TimeRelax)
{
	if (TimeRelax >= 0)
	{
		this->TimeRelax = TimeRelax;
	}
}

int Bus::getTimeRelax() const
{
	return TimeRelax;
}
void Bus::showInfo() const
{
	Time_ a = start;
	cout << "--- Num " << num << " ---" << endl;
	a.showTime();
	while (a <= stop)
	{
		cout << "-";
		 for (int i = 0; i < length; i++)
		{
			a.operator++();
		} 
			a += length;
		a.showTime();
		cout << endl;
		 for (int i = 0; i < TimeRelax; i++)
		{
			a.operator++();
		} 
			a += TimeRelax;
		if (a <= stop)
		{
			a.showTime();
		}
	}
}

ostream& operator<<(ostream& out, const Bus& obj)
{
	out << "num: " << obj.num << endl;
	out << "start time: " << obj.start << ":";
	out << "length: " << obj.length << endl;
	out << "TimeRelax: " << obj.TimeRelax << endl;
	out << "stop time: " << obj.stop << ":";
	return out;
}

istream& operator>>(istream& in, Bus& obj)
{
	cout << "Input num: ";
	in >> obj.num;
	cout << endl;
	cout << "Input length: ";
	in >> obj.length;
	cout << endl;
	cout << "Input TimeRelax: ";
	in >> obj.TimeRelax;
	cout << endl;
	return in;
}
