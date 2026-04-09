#pragma once
#pragma once
//该文件是修改后的Hash.h,适用于UnorderedSet.h和UnorderedMap.h
//1. 哈希表
//2. 封装map和set
//3. 普通迭代器
//4. const迭代器
//5. insert返回值  operator[]
//6. key不能修改的问题
//泛型编程:不是针对某种具体类型,针对广泛的类型(两种及以上)
#include<vector>
#include<iostream>
using namespace std;
template<class K>
struct DefaultHashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};
//仿函数
//struct StringHashFunc
//{
//	size_t operator()(const string& str)
//	{
//		return str[0];
//	}
//};
//特化
template<>
struct DefaultHashFunc<string>
{
	size_t operator()(const string& str)
	{
		//return str[0];

		//无法处理重复元素
		//size_t hash = 0;
		//for (auto ch : str)
		//{
		//	hash += ch;
		//}
		//return hash;

		//BKDR
		//不同的字符串是否会映射计算出相同的整形
		//字符串组合是无限的,size_t只有2^32
		//字符串太长不会影响时间复杂度
		size_t hash = 0;
		for (auto ch : str)
		{
			hash *= 131;
			hash += ch;
		}
		return hash;
	}
};
//开放地址法
//冲突会互相影响,相邻位置映射的值会互相影响
namespace open_address
{
	enum STATE
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;//K不能使用const K
		STATE _state = EMPTY;
	};

	//载荷因子=填入表的元素个数/散列表的长度
	//负载因子越大,冲突概率越大(空间利用率越高)
	//负载因子越小,冲突概率越小(空间利用率越低,浪费越大)
	//哈希表不能满了再扩容,控制负载因子到一定值就扩容
	template<class K, class V, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			_table.resize(10);
		}
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}
			//扩容
			//if (_n * 10 / _table._size() >= 7)
			if ((double)_n / _table.size() >= 0.7)
			{
				//_table.resize(newSize);//扩容后映射关系变了,需要重新映射
				size_t newSize = _table.size() * 2;
				//方法1
				//vector<HashData> newtable;
				//newtable.resize(newSize);
				//方法2
				//遍历旧表,重新映射到新表
				HashTable<K, V, HashFunc> newHT;
				newHT._table.resize(newSize);
				//遍历旧表的数据插入到新表即可
				for (size_t i = 0; i < _table.size(); i++)
				{
					if (_table[i]._state == EXIST)
					{
						newHT.Insert(_table[i]._kv);
					}
				}
				_table.swap(newHT._table);
			}
			//线性探测
			HashFunc hf;
			size_t hashi = hf(kv.first) % _table.size();//%capacity,[]不能访问size<=x<capacity的位置
			while (_table[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _table.size();
			}
			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_n;
			return true;
		}
		HashData<const K, V>* Find(const K& key)
		{
			//线性探测
			HashFunc hf;
			//size_t hashi = key % _table.size();//只有整形才能取模
			size_t hashi = hf(key) % _table.size();//仿函数
			//%capacity,[]不能访问size<=x<capacity的位置
			while (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._state == EXIST && _table[hashi]._kv.first == key)
				{
					return (HashData<const K, V>*) & _table[hashi];//类型转换
				}
				++hashi;
				hashi %= _table.size();
			}
			return nullptr;
		}
		//模版是按需编译
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			return false;
		}
	private:
		vector<HashData<K, V>> _table;
		size_t _n = 0;//存储有效数据的个数
	};
}

//拉链法/哈希桶
//指针数组
namespace hash_bucket
{
	template<class T>//不确定是key还是key_value
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;
		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{
		}
	};
	//前置声明
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	template<class K, class T, class Ptr, class Ref, class KeyOfT, class HashFunc>
	struct HTIterator
	{
		//哈希表要用迭代器,迭代器要使用哈希表
		typedef HashNode<T> Node;
		typedef HTIterator<K, T, Ptr, Ref, KeyOfT, HashFunc> Self;//不需要加typename

		const HashTable<K, T, KeyOfT, HashFunc>* _pht;
		Node* _node;
		
		HTIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			,_pht(pht)
		{ }
		HTIterator(Node* node, const HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			, _pht(pht)
		{
		}

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		Self& operator++()
		{
			if (_node->_next)
			{
				//当前桶还没有完
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				HashFunc hf;
				size_t hashi = hf(kot(_node->_data)) % _pht->_table.size();
				//从下一个位置开始查找下一个不为空的桶
				++hashi;
				while (hashi < _pht->_table.size())
				{
					if (_pht->_table[hashi])
					{
						_node = _pht->_table[hashi];
						return *this;
					}
					else
					{
						++hashi;
					}
				}
				_node = nullptr;
			}
			return *this;
		}
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
		bool operator==(const Self& s)
		{
			return _node == s._node;
		}
	};
	//set ---> hash_bucket::HashTable<K, K> _ht;
	//map ---> hash_bucket::HashTable<K, pair<K, V>> _ht;
	template<class K, class T,class KeyOfT, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
		typedef HashNode<T> Node;
		//友元声明
		template<class K, class T, class Ptr, class Ref, class KeyOfT, class HashFunc>
		friend struct HTIterator;
	public:
		typedef HTIterator<K, T, T*, T&, KeyOfT, HashFunc> iterator;
		typedef HTIterator<K, const T, const T*, const T&, KeyOfT, HashFunc> const_iterator;
		iterator begin()
		{
			//找第1个桶
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return iterator(cur, this);
				}
			}
			return iterator(nullptr, this);
		}
		iterator end()
		{
			return iterator(nullptr, this);//this传到构造函数是权限的放大
		}
		const_iterator begin() const
		{
			//找第1个桶
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return const_iterator(cur, this);
				}
			}
			return const_iterator(nullptr, this);
		}
		const_iterator end() const
		{
			return const_iterator(nullptr, this);//this传到构造函数是权限的放大
		}
		HashTable()
		{
			_table.resize(10, nullptr);
		}
		~HashTable()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}
		bool Insert(const T& data)
		{
			KeyOfT kot;
			if (Find(kot(data)))
			{
				return false;
			}
			//不扩容,不断插入,某些桶越来越长,效率得不到保证
			//负载因子适当的放大一些,负载因子控制在1,平均下来,每个桶一个数据
			//负载因子到1就扩容
			HashFunc hf;
			if (_n >= _table.size())
			{
				//这种思路不好
				size_t newSize = _table.size() * 2;
				//原因
				//HashTable<K, V> newht;
				//for (size_t i = 0; i < _table.size(); i++)
				//{
				//	newht.Insert();//Insert插入的是值
				//}
				vector<Node*> newTable;
				newTable.resize(newSize, nullptr);
				//遍历旧表,迁移节点挂接到新表
				for (size_t i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;
						//头插到新表
						size_t hashi = hf(kot(cur->_data)) % newSize;
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;
						cur = next;
					}
					_table[i] = nullptr;
				}
				_table.swap(newTable);
			}
			size_t hashi = hf(kot(data)) % _table.size();
			//头插
			Node* newnode = new Node(data);
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			++_n;
			return true;
		}
		void Print()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				printf("[%d]->", i);
				Node* cur = _table[i];
				while (cur)
				{
					cout << cur->_kv.first << ":" << cur->_kv.second << "->";
					cur = cur->_next;
				}
				printf("NULL\n");
			}
			cout << endl;
		}
		Node* Find(const K& key)
		{
			HashFunc hf;
			KeyOfT kot;
			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			HashFunc hf;
			KeyOfT kot;
			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					--_n;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}
	private:
		vector<Node*> _table;//指针数组
		//vector<list> _table;//也可以,list是任意位置插入,list不容易实现迭代器,list要写析构函数
		size_t _n = 0;//存储了多少个有效数据
	};
}