#define _CRT_SECURE_NO_WARNINGS 1 
//string类
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	//string是类名,s1是对象名
//	string s1;//展开
//	std::string s1;//不展开
//
//	std::string name("张三");
//	name = "李四";
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1;//string();
//	string s2("hello world");//string(const char* s);
//	string s3(10, '*');//n个字符初始化,string (size_t n, char c);
//	string s4(s2);//拷贝构造,string (const string& str);
//	string s5(s2, 6, 5);
//	cout << s5 << endl;
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1;
//	string s2("张三");
//	//operator=
//	s1 = s2;//string& operator=(const string & str);拷贝构造
//	cout << s1 << endl;
//
//	s1 = "1111";//string& operator=(const char* s);常量字符串
//	cout << s1 << endl;
//
//	s1 = '*';//string& operator=(char c);//字符
//	cout << s1 << endl;
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1;
//	string s2("张三");
//	string s3("hello world");
//	string s4(10, '*');
//	string s5(s2);//拷贝构造
//	string s6(s3, 6, 5);
//	//cout << s2 << endl;//支持流的运算符重载
//	//cout << s6 << endl;
//	
//	//比较
//	cout << (s1 == s2) << endl;
//	cout << (s1 < s2) << endl;
//	cout << (s1 > s2) << endl;
//
//	string s7(s3, 6);//如果没有给第3个参数,表示给了一个非常大的值
//	cout << s7 << endl;
//
//	string s8(s3, 6, 100);
//	cout << s8 << endl;
//
//	string url("https://legacy.cplusplus.com/reference/string/string/string/");
//	string sub1(url, 0, 5);
//	string sub2(url, 8, 20);
//	string sub3(url, 29);
//	//string sub3(url, 29, 100);
//	cout << sub1 << endl;
//	cout << sub2 << endl;
//	cout << sub3 << endl;
//
//	//operator=
//	s1 = s2;
//	cout << s1 << endl;
//
//	s1 = "1111";
//	cout << s1 << endl;
//
//	s1 = '*';
//	cout << s1 << endl;
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	//增
//	//string s1("hello");
//	////尾插一个字符
//	//s1.push_back(' ');
//	////尾插一个字符串
//	//s1.append("world");
//	////如果空间不够,会自动扩容
//	//cout << s1 << endl;
//
//	//string s2("Thank");
//	//s2 += ' ';//operator+=字符调用push_back
//	//s2 += "you";//operator+=字符调用appsend
//	//cout << s2 << endl;
//
//	int x = 0;
//	cin >> x;
//	//将x转成string对象
//	string xstr;
//	while (x)
//	{
//		size_t val = x % 10;
//		xstr += ('0' + val);
//		x /= 10;
//	}
//	//逆置
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int x = 0;
//	cin >> x;
//	string xstr;
//	while (x)
//	{
//		size_t val = x % 10;
//		xstr += ('0' + val);
//		x /= 10;
//	}
//	//逆置
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	string s1;
//	string s2("hello world");
//	
//	//遍历字符串
//	//方法1
//	//cout << s2 << endl;
//
//	//方法2
//	//下标+[]
//	//cout << s2.size() << endl;
//
//	//int i = 0;
//	//for (i = 0; i < s2.size(); i++)
//	//{
//	//	s2[i]++;
//	//}
//	//for (i = 0; i < s2.size(); i++)
//	//{
//	//	cout << s2[i];
//	//}
//	//cout << endl;
//
//	char s3[] = "hello world";
//	s2[1];//s1.operator[](1);
//	s3[1];//->*(s3 + 1)
//	return 0;
//}


//迭代器
//iterator提供一种统一的方式访问和修改容器中的数据,算法就可以通过迭代器,去处理容器中的数据。
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	//begin和end是左闭右开的关系
//	//[begin, end)
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	//写
//	while (it != s1.end())
//	{
//		(*it)--;
//		it++;
//	}
//	it = s1.begin();
//	//读
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	return 0;
//}


//范围for
//替换为迭代器
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1("hello world");
//	for (auto& ch : s1)
//	{
//		ch++;
//	}
//	for (auto ch : s1)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//	reverse(s1.begin(), s1.end());//reverse是一个函数模版,迭代器可以跟容器配合
//	for (auto ch : s1)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//	return 0;
//}


//任何容器都支持迭代器,并且用法是类似的
//iterator提供一种统一的方式访问和修改容器的数据
//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//using namespace std;
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	vector<int>::iterator vit = v.begin();
//	while (vit != v.end())
//	{
//		cout << *vit << " ";
//		vit++;
//	}
//	cout << endl;
//	return 0;
//}


//reverse
//反向迭代器
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1("hello world");
//	//string::reverse_iterator rit = s1.rbegin();
//	auto rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		(*rit) += 3;
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//	cout << s1 << endl;
//	return 0;
//}


//const修饰的迭代器
//#include<iostream>
//#include<string>
//using namespace std;
//void Func(string& s)//不加引用需要深拷贝,代价较大
//{
//	string::const_iterator it = s.begin();
//	//string::iterator it = s.begin();
//	//auto it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	string::const_reverse_iterator rit = s.rbegin();
//	while (rit != s.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//}
//int main()
//{
//	string s1("hello world");
//	Func(s1);
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1("hello world");
//	cout << s1.max_size() << endl;
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1("hello world");
//	//cout << s1.capacity() << endl;
//	/*size_t old = s1.capacity();
//	for (size_t i = 0; i < 100; i++)
//	{
//		s1 += 'x';
//		if (old != s1.capacity())
//		{
//			cout << "扩容" << s1.capacity() << endl;
//			old = s1.capacity();
//		}
//	}*/
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	s1.clear();
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1 << endl;
//	return 0;
//}


//reserve
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s1("hello world");
//	s1.reserve(100);
//	size_t old = s1.capacity();
//	cout << s1.capacity() << endl;
//	for (size_t i = 0; i < 100; i++)
//	{
//		s1 += 'x';
//		if (old != s1.capacity())
//		{
//			cout << "扩容" << s1.capacity() << endl;
//			old = s1.capacity();
//		}
//	}
//	s1.reserve(10);
//	old = s1.capacity();
//	cout << s1.capacity() << endl;
//	return 0;
//}


//如果开辟的空间没有存储数据,可以缩小空间
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1("hello world");
//	s1.reserve(100);
//	size_t old = s1.capacity();
//	for (size_t i = 0; i < 100; i++)
//	{
//		s1 += 'x';
//		if (old != s1.capacity())
//		{
//			cout << "扩容" << s1.capacity() << endl;
//			old = s1.capacity();
//		}
//	}
//	//有数据
//	cout << s1.capacity() << endl;
//	s1.reserve(10);
//	old = s1.capacity();
//	cout << s1.capacity() << endl;
//	//无数据
//	s1.clear();
//	cout << s1.capacity() << endl;
//	s1.reserve(10);
//	old = s1.capacity();
//	cout << s1.capacity() << endl;
//	return 0;
//}


//resize
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1("hello world");
//
//	//开空间
//	s1.reserve(100);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	
//	//开空间+初始化填数据
//	s1.resize(100, 'x');
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	s1.resize(4);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	return 0;
//}


//at
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1("hello world");
//	s1.at(0) = 'x';
//	cout << s1 << endl;
//	return 0;
//}


//operator[ ]越界会断言,at越界则是抛出异常。
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	//温和的错误处理
//	try
//	{
//		string s1("hello world");
//		s1.at(15) = 'x';//at越界
//		//s1[15] = 'x';//operator[ ]越界
//		cout << s1 << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}


//assign
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1("hello ");
//	//append追加
//	s1.append("world");
//	cout << s1 << endl;
//	
//	//覆盖
//	//s1.assign("111111111");
//	s1 = "11111111111111";
//	cout << s1 << endl;
//	return 0;
//}


//insert
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s1("world");
//	s1.insert(0, "hello ");
//	cout << s1 << endl;
//
//	s1.insert(s1.begin() + 3, 10, 'z');
//	cout << s1 << endl;
//	return 0;
//}


//erase
//#include<string>
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s1("hello world");
//	s1.erase(5, 1);
//	cout << s1 << endl;
//
//	s1.erase(5);
//	cout << s1 << endl;
//	return 0;
//}


//replace
//#include<string>
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s1("hello world");
//	s1.replace(6, 5, "xxxxxxxxxx");
//	cout << s1 << endl;
//
//	s1.replace(6, 10, "zzzz");
//	cout << s1 << endl;
//
//	string s2("hello world hello world");
//	string s3;
//	for (auto ch : s2)
//	{
//		if (ch == ' ')
//		{
//			s3 += "20%";
//		}
//		else
//		{
//			s3 += ch;
//		}
//	}
//	cout << s3 << endl;
//	cout << s3.c_str() << endl;
//	return 0;
//}


//c.str()
//c_str与c的一些接口函数配合
//#include<iostream>
//using namespace std;
//int main()
//{
//	string filename = "test.cpp";
//	FILE* fout = fopen(filename.c_str(), "r");
//	return 0;
//}


//find
//#include<iostream>
//using namespace std;
//int main()
//{
//	
//	string url = "https://legacy.cplusplus.com/reference/string";
//	int ret1 = url.find("://");
//	if (ret1 != string::npos)
//	{
//		string s1(url, 0, ret1);
//		cout << s1 << endl;
//	}
//	int ret2 = url.find('/', ret1 + 3);
//	if (ret1 != string::npos)
//	{
//		string s2(url, ret1 + 3, ret2 - (ret1 + 3));
//		cout << s2 << endl;
//	}
//	string s3(url, ret2 + 1, url.length());
//	cout << s3 << endl;
//	return 0;
//}


//to_string
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string stri = to_string(123);
//	string strf = to_string(123.123);
//	cout << stri << endl;
//	cout << strf << endl;
//	return 0;
//}


//#include "string.h"
//void test_string()
//{
//	//构造函数
//	//常量字符串
//	//str::string s1("hello world");
//	//cout << s1.c_str() << endl;
//
//	//无参
//	//str::string s2;
//	//cout << s2.c_str() << endl;
//
//	//非const对象
//	//for (size_t i = 0; i < s1.size(); i++)
//	//{
//	//	s1[i]++;
//	//}
//	//for (size_t i = 0; i < s1.size(); i++)
//	//{
//	//	cout << s1[i] << " ";
//	//}
//	//cout << endl;
//
//	//const对象
//	//const str::string s3("hello world");
//	//s3[0]++;//不能写
//	//s3[0];//只能读
//
//	//迭代器 --- 普通对象
//	//iterator在string的类域里面
//	//begin返回最开始的位置
//	//end返回最后的下一个位置
//	//str::string::iterator it = s1.begin();
//	//auto it = s1.begin();
//	//while (it != s1.end())
//	//{
//	//	(*it)++;//可读可写
//	//	cout << *it << " ";
//	//	it++;
//	//}
//	//cout << endl;
//
//	//const对象
//	//str::string::const_iterator cit = s3.begin();
//	//auto cit = s3.begin();
//	//while (cit != s1.end())
//	//{
//	//	//(*cit)++;//只读的
//	//	cout << *cit << " ";
//	//	cit++;
//	//}
//	//cout << endl;
//
//	//范围for
//	//被替换成了迭代器
//	//end和begin的大小写也不能更改
//	//for (auto ch : s1)
//	//{
//	//	cout << ch << " ";
//	//}
//	//cout << endl;
//
//	//push_back
//	//append
//	//s1.push_back(' ');
//	//s1.push_back('#');
//	//s1.append("hello wbb");
//	//cout << s1.c_str() << endl;
//
//	//+=
//	//s1 += ' ';
//	//s1 += '#';
//	//s1 += "hello mom";
//	//cout << s1.c_str() << endl;
//
//	//insert --- 字符
//	//s1.insert(-1, 3, '#');
//	//cout << s1.c_str() << endl;
//
//	//insert --- 字符串
//	//s1.insert(5, "%%");
//	//cout << s1.c_str() << endl;
//
//	//erase
//	//str::string s1("hello world");
//	//s1.erase(5, 30);
//	//cout << s1.c_str() << endl;
//
//	//find --- 字符
//	//str::string s1("hello world");
//	//cout << s1.find(' ') << endl;
//
//	//find --- 字符串
//	//str::string s1("hello world");
//	//cout << s1.find("lo") << endl;
//
//	//str::string url = "https://app.bestzixue.com/module";
//	//size_t pos1 = url.find("://");
//	//if (pos1 != str::string::_npos)
//	//{
//	//	str::string protocol = url.substr(0, pos1);
//	//	cout << protocol.c_str() << endl;
//	//}
//	//size_t pos2 = url.find('/', pos1 + 3);
//	//if (pos2 != str::string::_npos)
//	//{
//	//	str::string domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
//	//	cout << domain.c_str() << endl;
//	//	if (pos2 + 1 < url.size())
//	//	{
//	//		str::string uri = url.substr(pos2 + 1);
//	//		cout << uri.c_str() << endl;
//	//	}
//	//}
//
//	//resize
//	//std::string s1("hello world");
//	//s1.resize(8);
//	//cout << s1.c_str() << endl;
//	//s1.resize(13, 'x');
//	//cout << s1.c_str() << endl;
//	//s1.resize(20, 'y');
//	//cout << s1.c_str() << endl;
//
//	//<<
//	//std::string s1("hello world");
//	//s1.resize(8);
//	//cout << s1 << endl;
//	//s1.resize(13, 'x');
//	//cout << s1 << endl;
//	//s1.resize(20, 'y');
//	//cout << s1 << endl;
//
//	//c_str和<<的区别
//	//str::string s1("hello world");
//	//s1 += '\0';
//	//s1 += "aaaa";
//	//cout << s1.c_str() << endl;
//	//cout << s1 << endl;
//	//str::string copy(s1);
//	//cout << s1 << endl;
//	//cout << copy << endl;
//	//s1 += "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU";
//	//cout << s1 << endl;
//
//	//流提取>>
//	//str::string s;
//	//cin >> s;
//	//cout << s << endl;
//
//	//cin >> s;
//	//cout << s << endl;
//
//	//>
//	//hello world
//	//hello worldxxx
//
//	//hello\0xxxx
//	//hello\0yyyy
//	//string s1("hello");
//	//string s2("hello");
//	//cout << (s1 < s2) << endl;
//	//cout << (s1 > s2) << endl;
//	//cout << (s1 == s2) << endl << endl;
//
//	//string s3("hello");
//	//string s4("helloxxx");
//	//cout << (s3 < s4) << endl;
//	//cout << (s3 > s4) << endl;
//	//cout << (s3 == s4) << endl << endl;
//
//	//string s5("helloxxx");
//	//string s6("hello");
//	//cout << (s5 < s6) << endl;
//	//cout << (s5 > s6) << endl;
//	//cout << (s5 == s6) << endl << endl;
//
//	//拷贝
//	//str::string s1("hello");
//	//str::string s2(s1);
//	//cout << s1 << endl;
//	//cout << s2 << endl;
//
//	//赋值
//	//默认生成浅拷贝
//	//赋值是已经存在的2个对象
//	str::string s1("hello");
//	str::string s3("xxxxxxxxxxx");
//	s1 = s3;
//	s3 += '\0';
//	s3 += "tttt";
//	cout << s1 << endl;
//	cout << s3 << endl;
//	str::string s4(s3);
//	cout << s4 << endl;
//}
//int main()
//{
//	test_string();
//	return 0;
//}


//#include "string.h"
//void test_string()
//{
//	string s("hello");
//	for (auto ch : s)
//	{  
//		cout << ch << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	test_string();
//	return 0;
//}


//写时拷贝
//浅拷贝问题
//析构2次
//一个对象修改会影响另一个(写的时候引用计数如果不是1,则进行深拷贝,再修改)
//不同的平台计数是不一样的
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	std::string s1("hello world");
//	std::string s2(s1);
//	//深拷贝
//	printf("%p\n", s1.c_str());
//	printf("%p\n", s2.c_str());
//	s2[0]++;
//	printf("%p\n", s1.c_str());
//	printf("%p\n", s2.c_str());
//	cout << sizeof(s1) << endl;
//	return 0;
//}


//以空间换时间,字符串多会造成空间浪费
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	std::string s1("hello world");//size<16,字符串存在_Buf数组中
//	std::string s2("hello worldxxxxxxxxxxxxxxxxx");//size>=16,字符串存在_Ptr指向的堆空间中
//	return 0;
//}