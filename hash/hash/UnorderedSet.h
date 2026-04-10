#pragma once
#include"UnorderedHash.h"
//同一个类模板传不同的参数类型不同(类模板实例化不同的模版参数是不同的类型)
//vector<int> vector<char>
namespace Set
{
	template<class K>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::const_iterator const_iterator;
		const_iterator begin() const
		{
			return _ht.begin();
		}
		const_iterator end() const
		{
			return _ht.end();
		}
		pair<const_iterator, bool> insert(const K& key)//iterator是const_iterator
		{
			//方法1
			//编译器没有严格检查
			//return _ht.Insert(key);
			//方法2
			//推荐
			pair<typename hash_bucket::HashTable<K, K, SetKeyOfT>::iterator, bool> ret = _ht.Insert(key);
			return pair<const_iterator, bool>(ret.first, ret.second);
		}
	private:
		hash_bucket::HashTable<K, K, SetKeyOfT> _ht;
	};
}
