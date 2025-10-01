#pragma once
#include<vector>
#include<list>
#include<iostream>
using namespace std;
namespace que
{
	template<class T, class Container>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.erase(_con.begin());//ǿ������,ʹ�ù��õĺ���erase,���Ƽ�,˳����ͷɾЧ�ʵ�
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