//#pragma once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//class Date
//{
//	//单个传递
//	//cout << d1;
//	//friend void operator<<(ostream& out, const Date& d);
//	
//	//连续赋值
//	//cout << d1 << d2 << d3;
//	//友元函数是声明,没有受到访问限定符的限制
//	friend ostream& operator<<(ostream& out, const Date& d);
//
//	//流提取
//	friend istream& operator>>(istream& out, Date& d);
//public:
//	//构造函数
//	Date(int year = 1, int month = 1, int day = 1);
//
//	void Print()   const//const修饰this指针(*this),由原来的Date* this变为const Date* this
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	bool operator<(const Date& x);
//	bool operator==(const Date& x);
//	bool operator>(const Date& x);
//	bool operator<=(const Date& x);
//	bool operator>=(const Date& x);
//	bool operator!=(const Date& x);
//	int GetMonthDay(int year, int month);
//	Date& operator+=(int day);
//	Date operator+(int day);
//	//前置++
//	Date& operator++();
//	//后置++
//	//int是为了占位,不是为了接受具体的值,方便区分,为了跟前置++构成重载
//	Date operator++(int);
//
//	Date& operator-=(int day);
//
//	Date operator-(int day);
//	//前置--
//	Date& operator--();
//
//	//后置--
//	Date operator--(int);
//
//	int operator-(const Date& d);
//	//流插入不能写成成员函数,因为Date对象默认占用了第1个参数,做了左操作数,不符合使用习惯
//	//d1 << cout;
//	//void operator<<(ostream& out);
//	//int GetYear();
//	//int GetMonth();
//	//int GetDay();
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////全局变量
////void operator<<(ostream& out, Date& d);
//
////#include <iostream>
////#include <assert.h>
////using namespace std;
////class Date
////{
////public:
////	//构造函数
////	Date(int year, int month, int day)
////	{
////		if (month > 0 && month < 13 && day > 0 && day < GetMonthDay(year, month))
////		{
////			_year = year;
////			_month = month;
////			_day = day;
////		}
////		else
////		{
////			cout << "非法日期" << endl;
////			assert(false);
////		}
////	}
////	void Print()   const//const修饰this指针(*this),由原来的Date* this变为const Date* this
////	{
////		cout << _year << "-" << _month << "-" << _day << endl;
////	}
////	//前置++
////	Date& operator++();
////	//后置++
////	//int是为了占位,不是为了接受具体的值,方便区分,为了跟前置++构成重载
////	Date operator++(int);
////
////	////前置--
////	//Date& operator--();
////
////	////后置--
////	//Date operator--(int);
////private:
////	int _year;
////	int _month;
////	int _day;
////};
//
//
//#include <iostream>
//#include <assert.h>
//using namespace std;
//class Date
//{
//public:
//	//构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2025, 7, 14);
//	cout << d1 << endl;
//	return 0;
//}