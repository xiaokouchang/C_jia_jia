//#pragma once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//class Date
//{
//	//��������
//	//cout << d1;
//	//friend void operator<<(ostream& out, const Date& d);
//	
//	//������ֵ
//	//cout << d1 << d2 << d3;
//	//��Ԫ����������,û���ܵ������޶���������
//	friend ostream& operator<<(ostream& out, const Date& d);
//
//	//����ȡ
//	friend istream& operator>>(istream& out, Date& d);
//public:
//	//���캯��
//	Date(int year = 1, int month = 1, int day = 1);
//
//	void Print()   const//const����thisָ��(*this),��ԭ����Date* this��Ϊconst Date* this
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
//	//ǰ��++
//	Date& operator++();
//	//����++
//	//int��Ϊ��ռλ,����Ϊ�˽��ܾ����ֵ,��������,Ϊ�˸�ǰ��++��������
//	Date operator++(int);
//
//	Date& operator-=(int day);
//
//	Date operator-(int day);
//	//ǰ��--
//	Date& operator--();
//
//	//����--
//	Date operator--(int);
//
//	int operator-(const Date& d);
//	//�����벻��д�ɳ�Ա����,��ΪDate����Ĭ��ռ���˵�1������,�����������,������ʹ��ϰ��
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
////ȫ�ֱ���
////void operator<<(ostream& out, Date& d);
//
////#include <iostream>
////#include <assert.h>
////using namespace std;
////class Date
////{
////public:
////	//���캯��
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
////			cout << "�Ƿ�����" << endl;
////			assert(false);
////		}
////	}
////	void Print()   const//const����thisָ��(*this),��ԭ����Date* this��Ϊconst Date* this
////	{
////		cout << _year << "-" << _month << "-" << _day << endl;
////	}
////	//ǰ��++
////	Date& operator++();
////	//����++
////	//int��Ϊ��ռλ,����Ϊ�˽��ܾ����ֵ,��������,Ϊ�˸�ǰ��++��������
////	Date operator++(int);
////
////	////ǰ��--
////	//Date& operator--();
////
////	////����--
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
//	//���캯��
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