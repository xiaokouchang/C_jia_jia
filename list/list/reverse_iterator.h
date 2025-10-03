#pragma once

namespace ita
{
	template<class Iterator,class Ref,class Ptr>
	struct ReverseIterator
	{
		typedef ReverseIterator<Iterator, Ref, Ptr> self;
		Iterator _it;
		ReverseIterator(Iterator it)
			:_it(it)
		{}
		//返回值
		//方法1萃取
		//stl_iterator.h
		//template <class _Iterator>
		//class reverse_iterator
		//{
		//protected:
		//	_Iterator current;
		//public:
		//	typedef typename iterator_traits<_Iterator>::iterator_category
		//		iterator_category;
		//	typedef typename iterator_traits<_Iterator>::value_type
		//		value_type;
		//	typedef typename iterator_traits<_Iterator>::difference_type
		//		difference_type;
		//	typedef typename iterator_traits<_Iterator>::pointer
		//		pointer;
		//	typedef typename iterator_traits<_Iterator>::reference
		//		reference;

		//	typedef _Iterator iterator_type;
		//	typedef reverse_iterator<_Iterator> _Self;
		
		//方法2
		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);
		}
		Ptr operator->()
		{
			return &(operator*());
		}
		self operator++()
		{
			--_it;
			return *this;
		}
		self operator--()
		{
			++_it;
			return *this;
		}
		self& operator++(int)
		{
			self tmp(*this);
			--(*this);
			return tmp;
		}
		self& operator--(int)
		{
			self tmp(*this);
			++(*this);
			return tmp;
		}
		bool operator!=(const self& s) const
		{
			return _it != s._it;
		}
	};
}
