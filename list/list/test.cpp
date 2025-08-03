#define _CRT_SECURE_NO_WARNINGS 1 
//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	//list遍历的方式不能使用下标+[]的方式,因为双向循环链表不是连续的空间
//	list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	//for (auto e : lt)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	return 0;
//}


//#include<iostream>
//#include<list>
//#include<algorithm>
//#include<vector>
//#include<deque>
//using namespace std;
//void test1()
//{
//	//迭代器的区别
//	//list
//	//list<int> lt;
//	//lt.push_back(1);
//	//lt.push_back(2);
//	//lt.push_back(3);
//	//lt.push_back(4);
//	//auto it = lt.begin();
//	//for (size_t i = 0;i < 2;i++)
//	//{
//	//	it++;
//	//}
//	//lt.insert(it, 20);
//	//for (auto e : lt)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	////vector
//	//vector<int> v;
//	//v.push_back(1);
//	//v.push_back(2);
//	//v.push_back(3);
//	//v.push_back(4);
//	//auto ie = v.begin() + 2;
//	//v.insert(ie, 20);
//	//for (auto e : v)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	//查找
//	//list<int> lt;
//	//lt.push_back(1);
//	//lt.push_back(2);
//	//lt.push_back(3);
//	//lt.push_back(4);
//	//auto it = find(lt.begin(), lt.end(), 3);
//	////insert以后,迭代器不失效
//	////if (it != lt.end())
//	////{
//	////	lt.insert(it, 30);
//	////	*it *= 100;
//	////}
//	////erase以后,迭代器失效
//	//if (it != lt.end())
//	//{
//	//	lt.erase(it);
//	//	*it *= 100;
//	//}
//	//for (auto it : lt)
//	//{
//	//	cout << it << " ";
//	//}
//	//cout << endl;
//}
//void test2()
//{
//	//list和algorithm中函数的区别
//	//list<int> lt;
//	//lt.push_back(1);
//	//lt.push_back(2);
//	//lt.push_back(3);
//	//lt.push_back(4);
//	//for (auto e : lt)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	//reverse(lt.begin(), lt.end());
//	//for (auto e : lt)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	//lt.reverse();
//	//for (auto e : lt)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	//sort
//	srand(time(0));
//	const int N = 5000000;
//	vector<int> v;
//	v.reserve(N);
//	list<int> lt1;
//	for (int i = 0; i < N; i++)
//	{
//		auto e = rand();
//		v.push_back(e);
//		lt1.push_back(e);
//	}
//	//拷贝到vector排序,排完以后再拷贝回来
//	int begin1 = clock();
//	for (auto e : lt1)
//	{
//		v.push_back(e);
//	}
//	sort(v.begin(), v.end());
//	size_t i = 0;
//	for (auto e : lt1)
//	{
//		e = v[i++];
//	}
//	int end1 = clock();
//	int begin2 = clock();
//	lt1.sort();
//	int end2 = clock();
//	printf("vector sort:%d\n", end1 - begin1);
//	printf("list sort:%d\n", end2 - begin2);
//}
//void test3()
//{
//	//remove
//	//find+erase
//	//list<int> lt;
//	//lt.push_back(1);
//	//lt.push_back(2);
//	//lt.push_back(3);
//	//lt.push_back(4);
//	//lt.remove(5);
//	//for (auto e : lt)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	//splice --- 转移链表的数字
//	list<int> lt1, lt2;
//	list<int>::iterator it;
//	for (int i = 1; i <= 4; i++)
//	{
//		lt1.push_back(i);
//	}
//	for (int i = 1; i <= 3; i++)
//	{
//		lt2.push_back(i * 10);
//	}
//	it = lt1.begin();
//	it++;//指向2
//	lt1.splice(it, lt2, ++lt2.begin(), lt2.end());
//	for (auto e : lt1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	test3();
//	return 0;
//}


//在链表中删除所有的偶数
//#include<iostream>
//#include<list>
//#include<vector>
//using namespace std;
//int main()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	list<int>::iterator it = lt.begin();
//	while(it != lt.end())
//	{
//		if (*it % 2 == 0)
//		{
//			it = lt.erase(it);
//		}
//		else
//		{
//			it++;
//		}
//	}
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include "list.h"
//using namespace lt;
//int main()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	list<int>::iterator it = lt.begin();//拷贝构造
//	//迭代器的本质是通过对原生指针的封装来达到目的
//	while (it != lt.end())
//	{
//		//(*it)+=1;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	print(lt);
//	return 0;
//}


//#include "list.h"
//using namespace lt;
//int main()
//{
//	list<A> lt;
//	lt.push_back(A(1, 1));
//	lt.push_back(A(2, 2));
//	lt.push_back(A(3, 3));
//	lt.push_back(A(4, 4));
//	list<A>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		//cout << (*it)._a1 << " " << (*it)._a2 << endl;
//		cout << it->_a1 << " " << it->_a2 << endl;//A*_a1
//		//cout << it->->_a1 << " " << it->->_a2 << endl;
//		//严格来说,it->->_a1符合语法,因为运算符重载要求可读性,那么编译器特殊处理,省略了一个箭头
//		it++;
//	}
//	return 0;
//}


#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> lt = { 1, 2, 3, 4 };
    //const迭代器(只读)
    list<int>::const_iterator cit = lt.begin();
    while (cit != lt.end()) 
    {
        cout << *cit << " ";  // 2 4 6 8（无法修改）
        ++cit;
    }
    cout << endl;
    //普通迭代器(可读可写)
    list<int>::iterator it = lt.begin();
    while (it != lt.end())
    {
        *it *= 2;  //修改元素
        cout << *it << " "; // 2 4 6 8
        ++it;
    }
    cout << endl;
    //范围for循环(只读,等价于const迭代器)
    for (auto e : lt) 
    {
        cout << e << " ";  // 2 4 6 8
    }
    cout << endl;
    return 0;
}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	return 0;
//}


