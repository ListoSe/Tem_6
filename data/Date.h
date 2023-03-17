#pragma once
#include<iostream>
#include<ctime>
using namespace std;
class Date

{
	int year;
	int month;
	int day;
	bool isLeapYear()const; //Проверка на високосный год
	int monthDays()const; //Количество дней по месяцу
	void nextDate(); //Следующая дата
	void prevDate(); //Предыдущая дата
	

public:
	Date(); // По умолчанию  - текущая дата
	Date(int year, int month, int day); //С параметрами - заданная дата
	Date(const Date& obj); //Копирования
	Date& operator = (const Date& obj);
	~Date();// Деструктор

	void showDate()const;

	void setYear(int year);
	int getYear()const;
	void setMonth(int month);
	int getMonth()const;
	void setDay(int day);
	int getDay()const;

	bool valid()const; //Проверка даты на корректность

	bool operator == (const Date& obj)const&;
	bool operator != (const Date& obj)const&;
	bool operator > (const Date& obj)const&;
	bool operator < (const Date& obj)const&;
	bool operator >= (const Date& obj)const&;
	bool operator <= (const Date& obj)const&;

	//--------- ОПЕРАТОРЫ ПРИСВОЕНИЯ ---------      
	Date& operator += (int days); //добавить days дней к дате
	Date& operator -= (int days); //вычесть days дней из даты
	Date& operator += (float months); //добавить months месяцев к дате
	Date& operator -= (float months); //вычесть months месяцев из даты
	Date& operator += (long years); //добавить years лет к дате
	Date& operator -= (long years); //вычесть years лет из даты

	Date operator + (int days)const&;
	Date operator - (int days)const&;
	Date operator + (float months)const&; //добавить months месяцев к дате
	Date operator - (float months)const&; //вычесть months месяцев из даты
	Date operator + (long years)const&; //добавить years лет к дате
	Date operator - (long years)const&; //вычесть years лет из даты

	

	friend Date operator + (int n, Date a);
	friend Date operator - (int n, Date a);
	
	friend ostream& operator << (ostream& os, const Date& t);
	friend istream& operator >> (istream& is, Date& t);

	Date& operator -- ();//префиксная --i
	Date operator -- (int);//постфиксная i--
	Date& operator ++ ();
	Date operator ++ (int);
};

