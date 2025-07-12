#define _CRT_SECURE_NO_WARNINGS 1 


#include"Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}


bool Date::operator<(const Date& x)
{
	if (this->_year < x._year)//这里等价于if (this->_year < x._year)
	{
		return true;
	}
	else if (this->_year == x._year && this->_month < x._month)
	{
		return true;
	}
	else if (this->_year == x._year && this->_month == x._month && this->_day < x._day)
	{
		return true;
	}
	return false;
}


bool Date::operator==(const Date& x)
{
	return _year = x._year && _month > x._month && _day == x._day;
}


bool Date::operator>(const Date& x)
{
	return !(*this <= x);
}


bool Date::operator<=(const Date& x)
{
	return *this < x || *this == x;
}


bool Date::operator>=(const Date& x)
{
	return !(*this < x);
}

bool Date::operator!=(const Date& x)
{
	return !(*this == x);
}


Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= day;
	}
	//方法1
	*this = *this + day;//赋值
	return *this;

	//方法2
	//_day += day;
	//while (_day > GetMonthDay(_year, _month))
	//{
	//	_day -= GetMonthDay(_year, _month);
	//	_month++;
	//	if (_month > 12)
	//	{
	//		_month = 1;
	//		_year++;
	//	}
	//}
	//return *this;
}
Date Date::operator+(int day)
{
	//拷贝构造函数
	//方法1
	Date tmp(*this);
	//+=复用
	tmp += day;
	return tmp;
	
	//+
	//tmp._day += day;
	//while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	//{
	//	tmp._day -= GetMonthDay(tmp._year, tmp._month);
	//	tmp._month++;
	//	if (tmp._month > 12)
	//	{
	//		tmp._month = 1;
	//		tmp._year++;
	//	}
	//}
	//return tmp;
}

int Date::GetMonthDay(int year, int month)
{
	static int daysArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0) && year % 100 != 0) || (year % 400 == 0))
	{
		return 29;
	}
	else
	{
		return daysArr[month];
	}
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

Date& Date::operator-=(int day)
{
	
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *(this);
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}