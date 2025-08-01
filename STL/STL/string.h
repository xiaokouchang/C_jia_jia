#pragma once
//kmp算法
//BM字符串
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
namespace str
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin() 
		{
			return _str;
		}
		iterator end() 
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		void insert(size_t pos, size_t n, char ch)
		{
			assert(pos <= _size);
			if (_size + n > _capacity)
			{
				//至少扩容到_size + len
				reserve(_size + n);
			}
			//挪动数据
			int end = _size;//整形提升
			while (end >= pos && end != _npos)
			{
				_str[end + n] = _str[end];
				end--;
			}
			for (size_t i = 0; i < n; i++)
			{
				_str[pos + i] = ch;
			}
			_size += n;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size;
			while (end >= pos && end != _npos)
			{
				_str[end + len] = _str[end];
				end--;
			}
			for (size_t i = 0; i < len; i++)
			{
				_str[pos + i] = str[i];
			}
			_size += len;
		}

		//分开写
		//string(const char* str)
		//	: _size(strlen(str))
		//	, _capacity(strlen(str))
		//	, _str(new char[strlen(str) + 1])//开辟空间
		//{
		//	strcpy(_str, str);//拷贝数据
		//}
		//string()
		//	: _size()
		//	, _capacity()
		//	, _str(new char[1])//开辟空间
		//{
		//	_str[0] = '\0';
		//}

		//合并
		//string(const char* str = "\0")
		string(const char* str = "")//常量字符串后面默认有\0
			: _size(strlen(str))
			, _capacity(strlen(str))
			, _str(new char[strlen(str) + 1])//开辟空间
		{
			//c语言到\0终止,C++到_size结束
			//strcpy(_str, str);//拷贝数据
			memcpy(_str, str, _size + 1);//拷贝数据
		}
		//方法1
		//string(const string& s)
		//{
		//	_str = new char[s._capacity + 1];
		//	//strcpy(_str, s._str);
		//	memcpy(_str, s._str, s._size + 1);
		//	_size = s._size;
		//	_capacity = s._capacity;
		//}
		//方法2
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			,_capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}
		const char* c_str() const
		{
			return _str;
		}
		size_t size() const
		{
			return _size;
		}
		//方法1
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		memcpy(tmp, s._str, s._size + 1);
		//		delete[] _str;
		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}
		//	return *this;
		//}
		//方法2
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		std::swap(_str, tmp._str);
		//		std::swap(_size, tmp._size);
		//		std::swap(_capacity, tmp._capacity);
		//		//std::swap(tmp, *this);
		//	}
		//	return *this;
		//}
		//方法3
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		//this->swap(tmp);
		//		swap(tmp);
		//	}
		//	return *this;
		//}
		//方法4
		string& operator=(string tmp)
		{
			swap(tmp);
			return *this;
		}
		//读写 --- 普通对象
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		//读 --- const对象
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				//strcpy(tmp, _str);
				memcpy(tmp, _str, _size + 1);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				//2倍扩容
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				//至少扩容到_size + len
				reserve(_size + len);
			}
			//strcpy(_str + _size, str);
			memcpy(_str + _size, str, len + 1);
			_size += len;
		}
		string& operator+=(char str)
		{
			push_back(str);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void erase(size_t pos, size_t len = _npos)
		{
			assert(pos <= _size);
			if (len == _npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
				_str[_size] = '\0';
			}
			else
			{
				size_t end = pos + len;
				while (end <= _size)
				{
					_str[pos] = _str[end++];
				}
				_size -= len;
			}
		}
		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return _npos;
		}
		string substr(size_t pos = 0, size_t len = _npos)
		{
			assert(pos < _size);
			size_t n = len;
			if (len == _npos || pos + len > _size)
			{
				n = _size - pos;
			}
			string tmp;
			tmp.reserve(n);
			for (size_t i = pos; i < pos + n; i++)
			{
				tmp += _str[i];
			}
			return tmp;
		}
		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, str);
			if (ptr)
			{
				return ptr - _str;
			}
			else
			{
				return _npos;
			}
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		bool operator<(const string& s) const
		{
			int ret = memcmp(_str, s._str, _size < s._size ? _size : s._size);
			return ret == 0 ? _size < s._size : ret;

			//size_t i1 = 0;
			//size_t i2 = 0;
			//while (i1 < _size && i2 < s._size)
			//{
			//	if (_str[i1] < s._str[i2])
			//	{
			//		return true;
			//	}
			//	else if (_str[i1] < s._str[i2])
			//	{
			//		return false;
			//	}
			//	else
			//	{
			//		i1++;
			//		i2++;
			//	}
			//}

			////if (i1 == _size && i2 != s._size)
			////{
			////	return true;
			////}
			////else
			////{
			////	return false;
			////}

			//return i1 == _size && i2 != s._size;
			////return _size < s._size;
		}
		bool operator==(const string& s) const
		{
			return _size == s._size &&
				memcmp(_str, s._str, _size) == 0;
		}
		bool operator>(const string& s) const
		{
			return !(*this <= s);
		}
		bool operator<=(const string& s) const
		{
			return *this < s || *this == s;
		}
		bool operator>=(const string& s) const
		{
			return !(*this < s);
		}
		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}
		const static size_t _npos;//静态成员函数不能使用缺省值,缺省值是给初始化列表,const静态且是整型可以
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		//建议这里不要传缺省值,声明和定义分离
		//const static double x = 2.2;//只有整形(size_t,int)可以使用const传缺省值,其余的类型不可以
	};
	const size_t string::_npos = -1;
	//流插入和流提取不允许拷贝
	ostream& operator<<(ostream& out, const string& s)
	{
		//for (size_t i = 0; i < s.size(); i++)
		//{
		//	out << s[i];
		//}
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch = in.get();
		//in >> ch;
		//处理缓冲区前面的空格或者换行
		while (ch == '\n' || ch == ' ')
		{
			ch = in.get();
		}
		char buff[128];
		int i = 0;
		while (ch != '\n' && ch != ' ')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}
	}
};
