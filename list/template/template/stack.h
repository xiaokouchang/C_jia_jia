#pragma once
#include<vector>
#include<list>
#include<iostream>
using namespace std;
namespace sta
{
	template<class T,class Container = vector<T>>
	class stack
	{
	public:
		void push(const T& x);
		void pop();
		T& top()
		{
			return _con.back();
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
	class A
	{
	public:
		void func1();
		void func2();
	};
}