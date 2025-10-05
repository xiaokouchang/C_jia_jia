#pragma once
#include<list>
#include<deque>
#include<iostream>
using namespace std;
namespace que
{
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
			//_con.erase(_con.begin());//ǿ������,ʹ�ù��õĺ���erase,���Ƽ�,˳����ͷɾЧ�ʵ�
		}
		T& top()
		{
			return _con.back();
		}
		size_t size()
		{
			return _con.size();
		}
		T& front()
		{
			return _con.front();
		}
		T& back()
		{
			return _con.back();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}