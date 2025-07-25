//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include"Date.h"
//
//Date::Date(int year, int month, int day)
//{
//	if (month > 0 && month < 13 && day > 0 && day < GetMonthDay(year, month))
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	else
//	{
//		cout << "非法日期" << endl;
//		assert(false);
//	}
//}
//
//bool Date::operator<(const Date& x)
//{
//	if (this->_year < x._year)//这里等价于if (this->_year < x._year)
//	{
//		return true;
//	}
//	else if (this->_year == x._year && this->_month < x._month)
//	{
//		return true;
//	}
//	else if (this->_year == x._year && this->_month == x._month && this->_day < x._day)
//	{
//		return true;
//	}
//	return false;
//}
//
//
//bool Date::operator==(const Date& x)
//{
//	return _year == x._year && _month == x._month && _day == x._day;
//}
//
//
//bool Date::operator>(const Date& x)
//{
//	return !(*this <= x);
//}
//
//
//bool Date::operator<=(const Date& x)
//{
//	return *this < x || *this == x;
//}
//
//
//bool Date::operator>=(const Date& x)
//{
//	return !(*this < x);
//}
//
//bool Date::operator!=(const Date& x)
//{
//	return !(*this == x);
//}
//
//
//Date& Date::operator+=(int day)
//{
//	if (day < 0)
//	{
//		return *this -= -day;
//	}
//	//方法1
//	//*this = *this + day;//赋值
//	//return *this;
//
//	//方法2
//	_day += day;
//	while (_day > GetMonthDay(_year, _month))
//	{
//		_day -= GetMonthDay(_year, _month);
//		_month++;
//		if (_month > 12)
//		{
//			_month = 1;
//			_year++;
//		}
//	}
//	return *this;
//}
//Date Date::operator+(int day)
//{
//	//拷贝构造函数
//	//方法1
//	Date tmp(*this);
//	//+=复用
//	tmp += day;
//	return tmp;
//	
//	//+
//	//Date tmp(*this);
//	//tmp._day += day;
//	//while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//	//{
//	//	tmp._day -= GetMonthDay(tmp._year, tmp._month);
//	//	tmp._month++;
//	//	if (tmp._month > 12)
//	//	{
//	//		tmp._month = 1;
//	//		tmp._year++;
//	//	}
//	//}
//	//return tmp;
//}
//
//int Date::GetMonthDay(int year, int month)
//{
//	static int daysArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//	{
//		return 29;
//	}
//	else
//	{
//		return daysArr[month];
//	}
//}
//
//Date& Date::operator++()
//{
//	*this += 1;
//	return *this;
//}
//
//Date Date::operator++(int)
//{
//	Date tmp = *this;
//	*this += 1;
//	return tmp;
//}
//
//Date& Date::operator-=(int day)
//{
//	if (day < 0)
//	{
//		return *this += -day;
//	}
//	_day -= day;
//	while (_day <= 0)
//	{
//		--_month;
//		if (_month == 0)
//		{
//			_month = 12;
//			--_year;
//		}
//		_day += GetMonthDay(_year, _month);
//	}
//	return *(this);
//}
//
//Date Date::operator-(int day)
//{
//	Date tmp(*this);
//	tmp -= day;
//	return tmp;
//}
//
//Date& Date::operator--()
//{
//	*this -= 1;
//	return *this;
//}
//
//
//Date Date::operator--(int)
//{
//	Date tmp = *this;//拷贝构造函数
//	*this -= 1;
//	return tmp;
//}
//
////d1 - d2
//int Date::operator-(const Date& d)
//{
//	Date max = *this;
//	Date min = d;
//	int flag = 1;
//	if (*this < d)
//	{
//		max = d;
//		min = *this;
//		flag = -1;
//	}
//	int n = 0;
//	while (min != max)
//	{
//		min++;
//		++n;
//	}
//	return n * flag;
//}
//
//
////void Date::operator<<(ostream& out)
////{
////	out << _year << "年" << _month << "月" << _day << "日" << endl;
////}
//
//
////友元函数
////单个传递
////void operator<<(ostream& out,const Date& d)
////{
////	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
////}
//
//
////连续赋值
//ostream& operator<<(ostream& out,const Date& d)
//{
//	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
//	return out;
//}
//
//
//istream& operator>>(istream& in, Date& d)
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	in >> d._year >> d._month >> d._day;
//	if (month > 0 && month < 13 && day > 0 && day < d.GetMonthDay(year, month))
//	{
//		d._year = year;
//		d._month = month;
//		d._day = day;
//	}
//	else
//	{
//		cout << "非法日期" << endl;
//		assert(false);
//	}
//	return in;
//}
//
//
////全局变量
////void operator<<(ostream& out, Date& d)
////{
////	out << d.GetYear() << "年" << d.GetMonth() << "月" << d.GetDay() << "日" << endl;
////}
//
//
////int Date::GetYear()
////{
////	return _year;
////}
//
//
////int Date::GetMonth()
////{
////	return _month;
////}
////
////
////int Date::GetDay()
////{
////	return _day;
////}
