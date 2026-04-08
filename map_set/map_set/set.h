#pragma once
#include"RBTree.h"
namespace Set
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& kv)//仿函数
			{
				return kv;
			}
		};
	public:
		//typename告诉编译器类模板是内嵌类型
		//内嵌类型有内部类和typedef两种
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;
		//iterator begin()
		//{
		//	return _t.begin();
		//}
		//iterator end()
		//{
		//	return _t.end();
		//}
		const_iterator begin() const
		{
			return _t.begin();
		}
		const_iterator end() const
		{
			return _t.end();
		}
		//iterator是Tree::const_iterator
		pair<iterator, bool> insert(const K& key) //const这里不能加const,const对象不能insert
		{
			//返回普通迭代器
			//普通对象调用insert
			//pair<RBTree::iterator, bool>
			//调用了pair的构造函数
			//pair(iterator x,bool y)
			//	:first(x)
			//	,second(y)
			//{ }
			pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> ret = _t.Insert(key);//iterator是普通迭代器
			//return中的iterator是const_iterator,first是普通迭代器,使用普通迭代器构造const迭代器
			//这个类被实例化成const迭代器时,这个函数是一个构造,支持普通迭代器构造const迭代器
			//这个类被实例化普通迭代器,这个函数是一个拷贝构造
			return pair<iterator, bool>(ret.first, ret.second);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}