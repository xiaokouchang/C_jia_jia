#pragma once
#include<iostream>
using namespace std;
class Date
{
	//��������
	//cout << d1;
	//friend void operator<<(ostream& out, const Date& d);
	
	//������ֵ
	//cout << d1 << d2 << d3;
	//��Ԫ����������,û���ܵ������޶���������
	friend ostream& operator<<(ostream& out, const Date& d);

	//����ȡ
	friend istream& operator>>(istream& out, Date& d);
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
	//ǰ��--
	Date& operator--();

	//����--
	Date operator--(int);

	int operator-(const Date& d);
	//�����벻��д�ɳ�Ա����,��ΪDate����Ĭ��ռ���˵�1������,�����������,������ʹ��ϰ��
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


//ȫ�ֱ���
//void operator<<(ostream& out, Date& d);