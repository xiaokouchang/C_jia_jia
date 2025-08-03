#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace lt
{
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;
		list_node(const T& val = T())//构造函数
			: _next(nullptr)
			, _prev(nullptr)
			, _val(val)
		{}
	};
	//typedef _list_iterator<T, T&, T*> iterator
	//typedef _list_iterator<T, const T&> const_iterator
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		typedef _list_iterator<T, Ref,Ptr> self;
		Node* _node;
		
		_list_iterator(Node* node)
			:_node(node)
		{}
		Ref operator*()
		{
			return _node->_val;
		}
		T* operator->()
		{
			return &_node->_val;
		}
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		self& operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self& operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		bool operator!=(const self& it) const//end是临时对象具有常性
		{
			return _node != it._node;
		}
		bool operator==(const self& it) const
		{
			return _node == it._node;
		}
	};
	template<class T>
	struct _list_const_iterator
	{
		typedef list_node<T> Node;
		Node* _node;

		_list_const_iterator(Node* node)
			:_node(node)
		{}

		const T& operator*()
		{
			return _node->_val;
		}
		_list_const_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		_list_const_iterator<T>& operator++(int)
		{
			_list_const_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		bool operator!=(const _list_const_iterator<T>& it)//end是临时对象具有常性
		{
			return _node != it._node;
		}
		bool operator==(const _list_const_iterator<T>& it)//end是临时对象具有常性
		{
			return _node == it._node;
		}
	};
	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		//typedef _list_const_iterator<T> const_iterator;//const迭代器
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		//这样设计迭代器不行,const迭代器希望本身不能修改,而不是类型不能改变
		//const迭代器指向的数据不能被修改,自己可以修改
		//const T* ptr1;
		//T* const ptr2;
		iterator begin()
		{
			//单参数的构造函数支持隐式类型转换
			//return iterator(_head->_next);
			return _head->_next;
		}
		iterator end()
		{
			//单参数的构造函数支持隐式类型转换
			//return iterator(_head->_prev);
			return _head;
		}
		const_iterator begin() const
		{
			//单参数的构造函数支持隐式类型转换
			//return const_iterator(_head->_next);
			return _head->_next;
		}
		const_iterator end() const
		{
			//单参数的构造函数支持隐式类型转换
			//return const_iterator(_head->_prev);
			return _head;
		}
		void empty_init()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
			_size = 0;
		}
		list()
		{
			empty_init();
		}
		list(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;

		}
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
				it++;
			}
			_size = 0;
		}
		void push_back(const T& x)
		{
			//方法1
			//Node* tail = _head->_prev;
			//Node* newnode = new Node(x);//调用拷贝构造函数
			////head   tail   newnode
			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;

			//方法2
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		//pos位置之前插入
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);
			prev->_next = newnode;
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			return newnode;
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			return next;
		}
		size_t size()
		{
			size_t sz = 0;
			iterator it = begin();
			while (it != end())
			{
				++sz;
				++it;
			}
			return sz;
		}
	private:
		Node* _head;
		size_t _size;
	};
	template<class T>
	void print(const list<T>& lt)
	{
		list<int>::const_iterator it = lt.begin();//拷贝构造
		while (it != lt.end())
		{
			//(*it)+=1;//内容不能被修改
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	struct A
	{
		A(int a1 = 0, int a2 = 0)
			:_a1(a2)
			,_a2(a2)
		{}
		int _a1;
		int _a2;
	};
}