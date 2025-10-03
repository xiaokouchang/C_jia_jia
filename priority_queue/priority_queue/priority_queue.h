#pragma once
#include<iostream>
#include<vector>
#include"Date.h"
using namespace std;
template<class T>
class Less
{
public: 
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};
template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};
namespace prior
{
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	private:
		void AdjustDown(int parent)
		{
			Compare com;
			//找左右孩子大的那一个
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child + 1], _con[child]))
				{
					child++;
				}
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[child], _con[parent]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
	public:
		priority_queue()
		{
		}
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				first++;
			}
			//建堆
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
			{
				AdjustDown(i);
			}
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);//从根开始
		}
		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}
		const T& top()
		{
			return _con[0];
		}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}
	private:
		Container _con;
	};
	struct LessPDate
	{
		bool operator()(const Date* p1, const Date* p2)
		{
			return *p1 < *p2;
		}
	};
};