#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	//构造函数
	Date(int year = 1, int month = 1, int day = 1);
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	bool operator<(const Date& x);
	bool operator==(const Date& x);
	bool operator>(const Date& x);
	bool operator<=(const Date& x);
	bool operator>=(const Date& x);
	bool operator!=(const Date& x);
	int GetMonthDay(int year, int month);
	Date& operator+=(int day);
	Date operator+(int day);
	//前置++
	Date& operator++();
	//后置++
	//int是为了占位,不是为了接受具体的值,方便区分,为了跟前置++构成重载
	Date operator++(int);

	Date& operator-=(int day);

	Date operator-(int day);
private:
	int _year;
	int _month;
	int _day;
};