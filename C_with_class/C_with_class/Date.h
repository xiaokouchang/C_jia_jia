#pragma once
#include<iostream>
using namespace std;
class Date
{
	//单个传递
	//cout << d1;
	//friend void operator<<(ostream& out, const Date& d);
	
	//连续赋值
	//cout << d1 << d2 << d3;
	//友元函数是声明,没有受到访问限定符的限制
	friend ostream& operator<<(ostream& out, const Date& d);

	//流提取
	friend istream& operator>>(istream& out, Date& d);
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
	//前置--
	Date& operator--();

	//后置--
	Date operator--(int);

	int operator-(const Date& d);
	//流插入不能写成成员函数,因为Date对象默认占用了第1个参数,做了左操作数,不符合使用习惯
	//d1 << cout;
	//void operator<<(ostream& out);
	//int GetYear();
	//int GetMonth();
	//int GetDay();
private:
	int _year;
	int _month;
	int _day;
};


//全局变量
//void operator<<(ostream& out, Date& d);