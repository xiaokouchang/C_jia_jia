#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace vec
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		//n个val初始化
		vector(size_t n, const T& val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			resize(n, val);
		}
		vector(int n, const T& val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			resize(n, val);
		}
		vector()
			: _start(nullptr)
		    , _finish(nullptr)
		    , _endofstorage(nullptr)
		{}
		//方法1
		//vector(const vector<T>& v)
		//	: _start(nullptr)
		//	, _finish(nullptr)
		//	, _endofstorage(nullptr)
		//{
		//	_start = new T[v.capacity()];
		//	memcpy(_start, v._start, sizeof(T) * v.size());
		//	_finish = _start + v.size();
		//	_endofstorage = _start + v.capacity();
		//}
		//方法2
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		//v1 = v2
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				int sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//T是自定义类型时,依次调用数组每个对象的析构函数,再释放整个空间
					//T是自定义类型时,会发生浅拷贝
					//memcpy(tmp, _start, sizeof(T) * sz);
					//T是string这样深拷贝的类,调用的是string的赋值重载,实现的是string的深拷贝
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				//方法1
				//_finish = tmp + size();
				//_start = tmp;
				//_endofstorage = _start + n;
				//方法2
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}
		void push_back(const T& x)
		{
			//方法1
			//if (_finish == _endofstorage)
			//{
			//	size_t newcapavity = capacity() == 0 ? 4 : capacity() * 2;
			//	reserve(newcapavity);
			//}
			//*_finish = x;
			//_finish++;
			//方法2
			insert(end(), x);
		}
		size_t capacity() const
		{
			return _endofstorage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}
		void insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				size_t newcapavity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapavity);
				pos = _start + len;//迭代器失效
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			_finish++;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			_finish--;
			return pos;
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}
		void pop_back()
		{
			erase(--end());
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	void print(const vector<int>& v)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}