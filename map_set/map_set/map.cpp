#include<iostream>
#include<string>
#include"map.h"//.h文件不包含没有被展开,不会被编译
#include"set.h"
using namespace std;
void func(const Map::map<int, int>& m)
{
	//两者是等价的
	auto mit = m.begin();
	//Map::map<int, int>::const_iterator mit = m.begin();
	while (mit != m.end())
	{
		//mit->first = 1;//编译报错pait<const K,V>
		//mit->second = 1;
		cout << mit->first << ":" << mit->second << endl;//*it调用operator*,对于set返回key
		++mit;
	}
}
void test1()
{
	Map::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(2, 2));
	//map允许修改value,不允许修改key,库里面map的迭代器是正常的迭代器和set不一样
	Map::map<int, int>::iterator mit = m.begin();
	while (mit != m.end())
	{
		//mit->first = 1;//编译报错pait<const K,V>
		mit->second = 1;
		cout << mit->first << ":" << mit->second << endl;//*it调用operator*,对于set返回key
		++mit;
	}
	//func(m);
	cout << endl;
	for (const auto& kv : m)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
	Set::set<int> s;
	s.insert(2);
	s.insert(5);
	s.insert(7);
	s.insert(2);
	s.insert(5);
	s.insert(7);
	Set::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//set不允许修改key,修改后,树不是搜索树,库里面iterator和const_iterator都是const_iterator
		//if (*it % 2 == 0)
		//{
		//	*it += 10;
		//}
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (const auto& e : s)//底层是迭代器
	{
		cout << e << " ";
	}
	cout << endl;
}
void test2()
{
	Map::map<string, string> dict;
	dict.insert(make_pair("sort", "xxx"));
	dict["left"];//插入
	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
	dict["left"] = "左边";//修改
	dict["sort"] = "排序";//修改
	dict["right"] = "右边";//修改
	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}