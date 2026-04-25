#pragma once
//map和set在源代码中都是key,value结构的红黑树
//map和set使用的是同一个类模板,传的是不同的参数
#include"RBTree.h"
namespace Map
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;
		//iterator可以修改value,不能修改key,const_iterator的key和value都不能修改
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}
		const_iterator begin() const
		{
			return _t.begin();
		}
		const_iterator end() const
		{
			return _t.end();
		}
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}