#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;
//struct��class������ʹ�÷����޶���
//ֻҪ���඼����ʹ�÷����޶���
//��д�����޶���,classĬ����˽�е�,structĬ���ǹ��е�
//�����Ͷ�����������ڿ������ռ�
class Stack
{
public:
	//��Ա����
	void Init(int defaultcapacity = 4);
	//����,�����������������Ͷ������
	//inline void Init(int defaultcapacity = 4);
	//�����涨��ĺ���Ĭ����inline
	void Push(int x)
	{
		a[top++] = x;
	}
	void Destory()
	{
		free(a);
		a = nullptr;
		top = capacity;
	}
	int Top()
	{
		return a[top - 1];
	}
	//��Ա����
	//����д�ڳ�Ա����֮ǰ��֮��
//private:
	int* a;      //����
	int top;     
	int capacity;
};

class A
{
public:
	//����,����
	void PrintA()
	{
		cout << _a << endl;
	}
private:
	//����,����
	char _a;
};


class A1 
{
public:
	void f1() 
	{

	}
private:
	int _a;
	char _ch;
};
//���н��г�Ա����
class A2 
{
public:
	void f2() 
	{

	}
};
//����ʲô��û��---����
class A3
{

};