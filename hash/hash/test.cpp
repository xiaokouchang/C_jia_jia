//Hashmap  ---> unordered_map
//Hashset  ---> unordered_set
//单向迭代器,没有rbegin,rend
//用法几乎和map,set相同
//unordered_xxx系列单向迭代器,unordered_xxx系列遍历出来不是有序的,性能比map和set高一些

//#include<iostream>
//#include<unordered_set>
//#include<unordered_map>
//#include<set>
//#include<vector>
//using namespace std;
//void test1()
//{
//	//只能去重,不能排序
//	unordered_set<int> us;
//	us.insert(3);
//	us.insert(1);
//	us.insert(3);
//	us.insert(4);
//	us.insert(5);
//	us.insert(0);
//	unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	unordered_map<string, string> dict;
//	dict["sort"] = "排序";
//	dict["insert"] = "插入";
//	dict["string"] = "字符串";
//	dict["left"];
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//	cout << endl;
//}
//void test2()
//{
//	//无序unordered_set比set快,有序的时候set快
//	const size_t N = 100000;
//	unordered_set<int> us;
//	set<int> s;
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//	for (size_t i = 0; i < N; i++)
//	{
//		v.push_back(rand());
//		//v.push_back(rand() + i);
//		//v.push_back(i);
//	}
//	size_t begin1 = clock();
//	for (auto e : v)
//	{
//		s.insert(e);
//	}
//	size_t end1 = clock();
//	cout << "set insert:" << end1 - begin1 << endl;
//
//	size_t begin2 = clock();
//	for (auto e : v)
//	{
//		us.insert(e);
//	}
//	size_t end2 = clock();
//	cout << "unordered_set insert:" << end2 - begin2 << endl;
//
//	size_t begin3 = clock();
//	for (auto e : v)
//	{
//		s.find(e);
//	}
//	size_t end3 = clock();
//	cout << "set find:" << end3 - begin3 << endl;
//
//	size_t begin4 = clock();
//	for (auto e : v)
//	{
//		us.find(e);
//	}
//	size_t end4 = clock();
//	cout << "unordered_set find:" << end4 - begin4 << endl << endl;
//
//	cout << "插入数据个数：" << s.size() << endl;
//	cout << "插入数据个数：" << us.size() << endl << endl;;
//
//	size_t begin5 = clock();
//	for (auto e : v)
//	{
//		s.erase(e);
//	}
//	size_t end5 = clock();
//	cout << "set erase:" << end5 - begin5 << endl;
//
//	size_t begin6 = clock();
//	for (auto e : v)
//	{
//		us.erase(e);
//	}
//	size_t end6 = clock();
//	cout << "unordered_set erase:" << end6 - begin6 << endl << endl;
//}
//int main()
//{
//	//test1();
//	//test2();
//	return 0;
//}


#include"Hash.h"
void test1()
{
	HashTable<int, int> ht;
	int a[] = { 1,111,4,7,15,25,44,9 };
	for (auto e : a)
	{
		ht.Insert(make_pair(e, e));
	}
	auto kv = ht.find(4);
	//kv->_kv.first = 40;
	kv->_kv.second = 400;
}
void test2()
{
	//HashTable<string, string, StringHashFunc> dict;
	HashTable<string, string> dict;
	dict.Insert(make_pair("sort", "排序"));
	dict.Insert(make_pair("left", "xxx"));
	auto pdata = dict.find("left");
	//pdata->_kv.first = "xx";
	pdata->_kv.second = "左边";
}
void test3()
{
	string s1("xxx");
	string s2("xxx");
	DefaultHashFunc<string> hf;
	cout << hf(s1) << endl;
	cout << hf(s2) << endl;
	cout << hf("abcd") << endl;
	cout << hf("bacd") << endl;
	cout << hf("abbe") << endl;
	cout << hf("https://legacy.cplusplus.com/reference/unordered_map/unordered_map/") << endl;
}
int main()
{
	test3();
	return 0;
}