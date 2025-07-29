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
//	//vector与string的区别
//	//vector<char> v;
//	//string str;
//	//string要求后面最后有\0,更好兼容c接口
//	//string有很多它的专用接口函数
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
//	//vector<vector<int>> vv;
//
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
//	////迭代器区间初始化
//	//vector<int> v3(v1.begin(), v1.end());
//	//for (auto p : v3)
//	//{
//	//	cout << p << " ";
//	//}
//	//cout << endl;
//	////其他类型
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
//	//升序 --- 默认的是less
//	int a[] = { 4,2,3,5 };
//	vector<int> v5(a, a + 4);
//	sort(v5.begin(), v5.end());
//	for (auto v : v5)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	//降序
//	//方法1 --- 有名对象
//	greater<int> gt;//降序
//	sort(v5.begin(), v5.end(), gt);
//	for (auto v : v5)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	//方法2 --- 匿名对象
//	sort(v5.begin(), v5.end(), greater<int>());
//	for (auto v : v5)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	//方法3 --- 反向迭代
//	sort(v5.rbegin(), v5.rend());
//	for (auto v : v5)
//	{
//		cout << v << " ";
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
//	sort(a, a + 4);
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
#include<iostream>
#include<vector>
using namespace std;
void Test()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
int main()
{
	Test();
	return 0;
}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	return 0;
//}


