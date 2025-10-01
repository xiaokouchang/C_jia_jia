#define _CRT_SECURE_NO_WARNINGS 1 
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//void test()
//{
//	//遍历的3种方式
//	//vector<int> v;
//	//v.push_back(1);
//	//v.push_back(2);
//	//v.push_back(3);
//	//v.push_back(4);
//	////方式1 - - - 循环
//	//for (size_t i = 0; i < 4; i++)
//	//{
//	//	cout << v[i] << " ";
//	//}
//	//cout << endl;
//	////方式2 - - - 范围for
//	//for (auto s : v)
//	//{
//	//	cout << s << " ";
//	//}
//	//cout << endl;
//	////方式3 - - - 迭代器
//	//vector<int>::iterator it = v.begin();
//	//while (it != v.end())
//	//{
//	//	cout << *it << " ";
//	//	it++;
//	//}
//	//cout << endl;
//
//
//	//vector与string的区别
//	//vector<char> v;
//	//string str;
//	//string要求后面最后有\0,更好兼容c接口
//	//string有很多它的专用接口函数
//
//
//	//vector<string> v;
//	////方法1
//	//string name1("张三");
//	//v.push_back(name1);
//	////方法2
//	////匿名对象
//	//v.push_back(string("张三"));
//	////方法3
//	//v.push_back("张三");
//
//
//	//vector<vector<int>> vv;
//	//vector<int> v1(10, 1);
//	//vector<string> v2(10, "***");
//	//for (auto e : v1)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	//for (auto p : v2)
//	//{
//	//	cout << p << " ";
//	//}
//	//cout << endl;
//	
//
//	////迭代器区间初始化
//	//vector<int> v1(10, 1);
//	//vector<int> v2(v1.begin(), v1.end());
//	//for (auto p : v2)
//	//{
//	//	cout << p << " ";
//	//}
//	//cout << endl;
//	
//
//	//其他类型
//	//string str("hello world");
//	//vector<char> v4(str.begin(), str.end());
//	//for (auto p : v4)
//	//{
//	//	cout << p << " ";
//	//}
//	//cout << endl;
//	//int a[] = { 1,2,3,4 };
//	////数组 --- 指针
//	//vector<int> v5(a, a + 4);
//	//for (auto p : v5)
//	//{
//	//	cout << p << " ";
//	//}
//	//cout << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int a[] = { 4,2,3,5 };
//	vector<int> v5(a, a + 4);
//	//升序 --- 默认的是less
//	//sort(v5.begin(), v5.end());
//	//for (auto v : v5)
//	//{
//	//	cout << v << " ";
//	//}
//	//cout << endl;
//	//降序
//	//方法1 --- 有名对象
//	//greater<int> gt;//降序
//	//sort(v5.begin(), v5.end(), gt);
//	//for (auto v : v5)
//	//{
//	//	cout << v << " ";
//	//}
//	//cout << endl;
//	//方法2 --- 匿名对象
//	//sort(v5.begin(), v5.end(), greater<int>());
//	//for (auto v : v5)
//	//{
//	//	cout << v << " ";
//	//}
//	//cout << endl;
//	////方法3 --- 反向迭代
//	//sort(v5.rbegin(), v5.rend());
//	//for (auto v : v5)
//	//{
//	//	cout << v << " ";
//	//}
//	//cout << endl;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    vector<int> first;                                // empty vector of ints
//    vector<int> second(4, 100);                       // four ints with value 100
//    vector<int> third(second.begin(), second.end());  // iterating through second
//    vector<int> fourth(third);                        // a copy of third
//
//    int myints[] = { 16,2,77,29 };
//    vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
//
//    cout << "The contents of fifth are:";
//    for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//    {
//        cout << ' ' << *it;
//    }
//    cout << endl;
//    return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	greater<int> gt;
//	int a[] = { 4,2,3,5 };
//	vector<int> v5(a, a + 4);
//	//方法1和方法2连续使用会输出降序
//	sort(v5.begin(), v5.end(), gt);
//	sort(v5.begin(), v5.end(), greater<int>());
//	for (auto v : v5)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	//方法1或者方法2和方法3同时使用会输出升序
//	sort(v5.rbegin(), v5.rend(), gt);
//	for (auto v : v5)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//int main()
//{
//	std::vector<int> foo(3, 0);
//	std::vector<int> bar(5, 0);
//
//	bar = foo;
//	foo = std::vector<int>();
//
//	std::cout << "Size of foo: " << int(foo.size()) << '\n';
//	std::cout << "Size of bar: " << int(bar.size()) << '\n';
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	string s1("hello world");
//	sort(s1.begin(), s1.end());
//	cout << s1 << endl;
//
//	//迭代器区间是左闭右开的
//	int a[] = { 4,2,3,5 };
//	sort(a, a + 3);
//	for (auto v : a)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	return 0;
//}


//resize
//reserve是为了减少扩容的消耗,防止直接插入的数据导致反复扩容
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> v;
//	//v.reserve(10);//reserve的_size是0,reserve刚开始会进行断言,导致程序崩溃
//	v.resize(10);
//	for (size_t i = 0; i < 10; i++)
//	{
//		v[i] = i;
//	}
//	for (auto v:v)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> v;
//	v.reserve(10);//开辟空间,没有初始化
//	for (size_t i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	for (auto v : v)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	return 0;
//}


//reserve
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> v;
//	v.reserve(10);
//	for (size_t i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	for (auto v : v)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include<vector>
//#include<iostream>
//using namespace std;
//int main()
//{
//	vector<int> vec;
//	vec.resize(10, 1);
//	for (auto e : vec)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	vec.assign(3, 2);
//	for (auto e : vec)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//void test()
//{
//	int a[] = { 2,13,4,5 };
//	vector<int> v(a, a + 4);
//	v.erase(v.begin() + 2);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v.insert(v.begin() + 1, 3);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int a[] = { 2, 5, 4, 3 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	//auto pos = find(v.begin(), v.end(), 3);
//	if (pos != v.end())
//	{
//		v.erase(pos);
//	}
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int a[] = { 2, 5, 4, 3, 3 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	auto pos = find(v.begin(), v.end(), 3);
//	while (pos != v.end())
//	{
//		v.erase(pos);
//		pos = find(v.begin(), v.end(), 3);
//		//pos = find(pos + 1, v.end(), 3);//迭代器失效
//	}
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


//扩容
//#include<iostream>
//#include<vector>
//using namespace std;
//void Test()
//{
//	size_t sz;
//	vector<int> v;
//	sz = v.capacity();
//	cout << "making v grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		v.push_back(i);
//		if (sz != v.capacity())
//		{
//			sz = v.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}


//vector的模拟实现
//#include "vector.h"
////#include<vector>
//#include<iostream>
//using namespace std;
//void test()
//{
//	//vec::vector<int> v1;
//	//v1.push_back(1);
//	//v1.push_back(2);
//	//v1.push_back(3);
//	//v1.push_back(4);
//	//v1.push_back(5);
//	//v1.push_back(5);
//	//v1.push_back(5);
//	//v1.push_back(5);
//	//for (auto e : v1)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	//v1.insert(v1.begin(), 100);
//	//for (size_t i = 0; i < v1.size(); i++)
//	//{
//	//	cout << v1[i] << " ";
//	//}
//	//cout << endl;
//	//print(v1);
//
//	//insert
//	//vec::vector<int> v1;
//	//v1.push_back(1);
//	//v1.push_back(2);
//	//v1.push_back(3);
//	//v1.push_back(4);
//	//v1.push_back(1);
//	//v1.push_back(2);
//	//v1.push_back(3);
//	//v1.push_back(4);
//	//vec::vector<int>::iterator pos = v1.begin() + 3;
//	////insert以后迭代器可能会失效(扩容)
//	////insert后面不能使用形参迭代器,因为他可能失效了
//	//v1.insert(pos, 100);
//	////*pos += 3;//传形参失效
//	//print(v1);
//
//	//erase
//	//vector<int> v1;
//	//v1.push_back(1);
//	//v1.push_back(2);
//	//v1.push_back(3);
//	//v1.push_back(4);
//	//v1.push_back(5);
//	////v1.erase(v1.begin());
//	//for (auto e : v1)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	//auto it = v1.begin() + 4;
//	//v1.erase(it);
//	////erase以后,迭代器失效了,不能访问
//	////vs会强制检查,访问会直接报错
//	//cout << *it << endl;
//	//it++;
//	//cout << *it << endl;
//	//for (auto e : v1)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	////print(v1);
//
//	//resize
//	//vec::vector<int> v;
//	//v.resize(10, 0);
//	//print(v);
//
//	//拷贝构造
//	//vec::vector<int> v;
//	//v.push_back(1);
//	//v.push_back(2);
//	//v.push_back(3);
//	//v.push_back(4);
//	//vec::vector<int> v1(v);//没有拷贝构造函数,就是浅拷贝,再析构时会析构2次
//	//vec::vector<int> v2;//没有拷贝构造函数,就是浅拷贝,再析构时会析构2次
//	//v2.resize(10, 1);
//	////赋值
//	//v1 = v2;
//	//print(v1);
//
//	//vec::vector<string> v;
//	//v.push_back("1111111111111111111");//支持隐式类型转换
//	//v.push_back("2222222222222222222");
//	//v.push_back("3333333333333333333");
//	//v.push_back("4444444444444444444");
//	//v.push_back("5555555555555555555");
//	//vec::vector<string> v1(v);
//	//for (auto& e : v1)//使用自定义类型建议传引用
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//
//	//n个val初始化
//	//vector(size_t n, const T& val = T())  --- 1
//	//vector(InputIterator first, InputIterator last)  --- 2
//	vec::vector<int> v1(10u, 1);//u代表无符号的整数,只有1可以选
//	vec::vector<string> v2(10, "1111");//只有1可以选
//	vec::vector<int> v3(10, 1);//1和2都可以选
//	//print(v1);
//}
//int main()
//{
//	test();
//	return 0;
//}


//在vector中,在erase和insert迭代器对象后,不能再访问这个迭代器,我们认为它失效,访问结果是未定义
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	vector<int> v{ 1, 2, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//		{
//			it = v.erase(it);
//		}
//		else
//		{
//			it++;
//		}
//	}
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int i = 0;
//	int j = int();
//	int k = int(1);
//	cout << i << endl;
//	cout << j << endl;
//	cout << k << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	string s1("111111");
//	string s2;
//	cout << sizeof(s1) << endl;
//	cout << sizeof(s2) << endl;
//	return 0;
//}

