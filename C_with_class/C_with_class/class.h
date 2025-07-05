#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;
//struct和class都可以使用访问限定符
//只要是类都可以使用访问限定符
//不写访问限定符,class默认是私有的,struct默认是公有的
//声明和定义的区别在于开不开空间
class Stack
{
public:
	//成员函数
	void Init(int defaultcapacity = 4);
	//不能,内联函数不能声明和定义分离
	//inline void Init(int defaultcapacity = 4);
	//类里面定义的函数默认是inline
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
	//成员变量
	//可以写在成员函数之前或之后
//private:
	int* a;      //声明
	int top;     
	int capacity;
};

class A
{
public:
	//健身房,篮球场
	void PrintA()
	{
		cout << _a << endl;
	}
private:
	//卧室,厨房
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
//类中仅有成员函数
class A2 
{
public:
	void f2() 
	{

	}
};
//类中什么都没有---空类
class A3
{

};