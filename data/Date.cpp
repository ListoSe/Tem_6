#include "Date.h"

bool Date::isLeapYear() const
{
	if (year % 4 != 0)
	{
		return false;
	}
	else {
		
		if (year % 100 == 0 && year % 400 != 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
}

int Date::monthDays() const
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		return 31;
	}
	else if(month == 2)
	{
		if (isLeapYear())
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
	else {
		return 0;
	}
}

void Date::nextDate()
{
	if (day == 31 && month == 12)
	{
		day = 1;
		month = 1;
		year++;
	}
	else if(day == monthDays())
	{
		day = 1;
		month++;
	}
	else
	{
		day++;
	}
}

void Date::prevDate()
{
	if (day == 1 && month == 1)
	{
		day = 31;
		month = 12;
		year--;
	}
	else if (day == 1)
	{
		month--;
		day = monthDays();
	}
	else
	{
		day--;
	}
}

Date::Date()
{
	struct tm* tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);

	year = 1900 + tim->tm_year;
	month = 1 + tim->tm_mon;
	day = tim->tm_mday;
}

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(const Date& obj)
{
	this->year = obj.year;
	this->month = obj.month;
	this->day = obj.day;
}

Date& Date::operator=(const Date& obj)
{
	this->year = obj.year;
	this->month = obj.month;
	this->day = obj.day;
	return *this;
}

Date::~Date()
{
}

void Date::showDate() const
{
	cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << endl;
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getYear() const
{
	return year;
}

void Date::setMonth(int month)
{
	this->month = month;
}

int Date::getMonth() const
{
	return month;
}

void Date::setDay(int day)
{
	if (day >= 1 && day <= monthDays())
	{
		this->day = day;
	}
}

int Date::getDay() const
{
	return day;
}

bool Date::valid() const
{
	if (month >= 1 && month <= 12 && day >= 1 && day <= monthDays())
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Date::operator==(const Date& obj) const&
{
	if (this->day == obj.day && this->month == obj.month && this->year == obj.year)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator!=(const Date& obj) const&
{
	return !(*this == obj);
}

bool Date::operator>(const Date& obj) const&
{
	if (year > obj.year)
	{
		return true;
	}
	else if (year == obj.year && month > obj.month)
	{
		return true;
	}
	else if (year == obj.year && month == obj.month && day > obj.day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator<(const Date& obj) const&
{
	return !(*this>obj) &&(*this != obj);
}

bool Date::operator>=(const Date& obj) const&
{
	return (*this > obj) || (*this == obj);
}

bool Date::operator<=(const Date& obj) const&
{
	return (*this < obj) || (*this == obj);
}

Date& Date::operator+=(int days)
{
	for (int i = 0; i < days; i++)
	{
		nextDate();
	}
	return*this;
}

Date& Date::operator-=(int days)
{
	for (int i = 0; i < days; i++)
	{
		prevDate();
	}
	return*this;
}

Date& Date::operator+=(float months)
{
	this->month += months;
	if (month > 12)
	{
		year += month / 12;
		month = (month % 12);
	}
	return *this;
}

Date& Date::operator-=(float months)
{
	this->month -= months;
	if (month < 1)
	{
		year -= abs(month) / 12;
		month = 12 +(this->month % 12);
	}
	return *this;
}

Date& Date::operator+=(long years)
{
	year += years;
	if (day > monthDays())
	{
		day = monthDays();
	}
	return *this;
}

Date& Date::operator-=(long years)
{
	year -= years;
	if (day > monthDays())
	{
		day = monthDays();
	}
	return *this;
}

Date Date::operator+(int days) const&
{
	Date tmp = *this;
	for (int i = 0; i < days; i++)
	{
		tmp.nextDate();
	}
	return tmp;
}

Date Date::operator-(int days) const&
{
	Date tmp = *this;
	for (int i = 0; i < days; i++)
	{
		tmp.prevDate();
	}
	return tmp;
}

Date Date::operator+(float months) const&
{
	Date tmp = *this;
	tmp.month += months;
	if (tmp.month > 12)
	{
		tmp.year += tmp.month / 12;
		tmp.month += (tmp.month % 12);
	}
	return tmp;
}

Date Date::operator-(float months) const&
{
	Date tmp = *this;
	tmp.month -= months;
	if (tmp.month < 1)
	{
		tmp.year += (abs (tmp.month / 12) +1);
		tmp.month += 12 +(tmp.month % 12);
	}
	return tmp;
}

Date Date::operator+(long years) const&
{
	return Date();
}

Date Date::operator-(long years) const&
{
	return Date();
}

Date& Date::operator--()
{
	this->prevDate();
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	this->prevDate();
	return tmp;
}

Date& Date::operator++()
{
	this->nextDate();
	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	this->nextDate();
	return tmp;
}

Date operator+(int n, Date a)
{
	for (int i = 0; i < n; i++)
	{
		a.nextDate();
		
	}
	return a;
}

Date operator-(int n, Date a)
{
	for (int i = 0; i < n; i++)
	{
		a.prevDate();
	}
	return a;
}

ostream& operator<<(ostream& os, const Date& t)
{
	os << t.day / 10 << t.day % 10 << "." << t.month / 10 << t.month % 10 << "." << t.year;
	return os;
}

istream& operator>>(istream& is, Date& t)
{
	do
	{
		cout << "dd mm yyyy: ";
		is >> t.day >> t.month >> t.year;
	} 
	while (!t.valid());
	return is;
}

