#pragma once
#include"UnorderedHash.h"

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
		iterator begin() const
		{
			return _ht.begin();
		}
		iterator end() const
		{
			return _ht.end();
		}
		bool insert(const K& key)
		{
			return _ht.Insert(key);
		}
	private:
		hash_bucket::HashTable<K, K, SetKeyOfT> _ht;
	};
}
