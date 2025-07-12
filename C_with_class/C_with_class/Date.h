#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	//���캯��
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
	//ǰ��++
	Date& operator++();
	//����++
	//int��Ϊ��ռλ,����Ϊ�˽��ܾ����ֵ,��������,Ϊ�˸�ǰ��++��������
	Date operator++(int);

	Date& operator-=(int day);

	Date operator-(int day);
private:
	int _year;
	int _month;
	int _day;
};