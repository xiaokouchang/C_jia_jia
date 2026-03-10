#include<map> //key/value
#include<set> //key
#include<iostream>
#include<string>
using namespace std;
class A
{
public:
	A(int a1, int a2)
		: _a1(a1)
		, _a2(a2)
	{
	}
private:
	int _a1;
	int _a2;
};
//set底层是红黑树
//红黑树是一种搜索树
//set单纯的存储数据,需要符合规则才能插入
//set的拷贝构造代价比较大,析构是树的析构,迭代器是双向迭代器
void test()
{
	//排序+去重
	//去重的原理是一个值已经有了,不需要插入(kay_value)
	//搜索的基础上加上平衡
	//搜索树形式多样没有底线
	//数据重复出现不能使用set,需要使用map
	set<int> s;//set不能修改,set的iterator和const_iterator都是const_iterator
	s.insert(3);
	s.insert(2);
	s.insert(4);
	s.insert(5);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	//set里面存储结构体可以实现key_value,比较麻烦
	//遍历
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//for (auto e : s)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//erease
	//auto pos = s.find(3);
	//s.erase(pos);//迭代器位置
	
	s.erase(3);//值
	s.erase(30);//值
	//值和迭代器的区别是这个值如果在,两种都删除,如果不在,迭代器会崩溃,传值会正常运行
	auto pos = find(s.begin(), s.end(), 3);//auto pos = s.find(3);
	//两个find有差异
	//auto pos = s.find(3);时间复杂度为O(log2N),建议使用这个
	//迭代器是暴力查找,时间复杂度为O(N)
	if (pos != s.end())
	{
		s.erase(pos);
	}
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test1()
{
	set<int> s;
	s.insert(3);
	s.insert(5);
	s.insert(8);
	s.insert(7);
	auto it = s.find(10);
	if (it != s.end())
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "找不到" << endl;
	}
	//count是计数
	if (s.count(5))
	{
		cout << "找到了" << endl;
	}


	//lower_bound 上边界
	//upper_bound 下边界
	//std::set<int> myset;
	//std::set<int>::iterator itlow, itup;
	//for (int i = 1; i < 10; i++)
	//{
	//	myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90
	//}
	//itlow = myset.lower_bound(35);//>=35,左边界
	//itup = myset.upper_bound(60);//>60
	//cout << *itlow << endl;
	//cout << *itup << endl;
	////删除是左闭右闭,查找是左闭右开
	//myset.erase(itlow, itup);//迭代器区间要求左闭右开
	//std::cout << "myset contains:";
	//for (auto e : myset)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
}
void test2()
{
	std::set<int> myset;
	std::set<int>::iterator itlow, itup;
	for (int i = 1; i <= 5; i++)
	{
		myset.insert(i * 10);   // myset: 10 20 30 40 50
	}
	std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
	ret = myset.equal_range(30);//返回两个区间的值
	itlow = ret.first;
	itup = ret.second;
	cout << *itlow << endl;
	cout << *itup << endl;
	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';
}
//https://legacy.cplusplus.com/reference/set/multiset/
void test3()
{
	//排序,不去重
	//键值对
	multiset<int> s;//和set的使用类似
	s.insert(3);
	s.insert(5);
	s.insert(8);
	s.insert(7);
	s.insert(7);
	s.insert(9);
	s.insert(7);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	
	//如果查找的值相同,返回的不一定是第1个值,是中序的第1个值
	auto pos = s.find(7);
	while (pos != s.end())
	{
		cout << *pos << " ";
		++pos;
	}

	//count和equal_range在multiset中比set有意义
	auto ret = s.equal_range(7);//返回两个区间的值,如果值不存在,返回不存在的区间,不一定是end,
	auto itlow = ret.first;//返回第1个7
	auto itup = ret.second;//返回最后一个7后面的值
	//左闭右开
	cout << *itlow << endl;
	cout << *itup << endl;
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test4()
{
	//map需要修改value
	//key不允许修改是因为修改key,搜索树结构被破坏
	//pair是类模板的结构
	map<string, string> dict;
	//pair涉及隐式类型转换
	pair<string, string> kv1("insert", "插入");
	pair<string, string> kv2("sort", "排序");
	pair<string, string> kv3("insert", "插入");
	dict.insert(kv1);
	
	//匿名对象
	dict.insert(pair<string, string>("insert", "插入"));
	
	//make_pair --- 构造两个对象进行返回,c++98
	dict.insert(make_pair("string", "字符串"));
	
	//c++11支持多参数的构造函数的隐式类型转换
	dict.insert({ "string", "字符串" });

	//单参数的构造函数支持隐式类型转换
	//构造+拷贝构造,编译器进行了优化
	string s = "hello";
	A aa1 = { 1,2 };
	//const pair<string, string>& kv2 = { "string","字符串" };
}
void test5()
{
	map<string, string> dict;
	dict.insert(make_pair("string", "字符串"));
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("insert", "插入"));
	//key相同value不相同,不会插入,不会覆盖,插入过程中只比较key
	//key已经有了就不插入
	
	//迭代器返回operator*,c++不支持返回两个值key和value,需要使用pair
	map<string, string>::iterator it = dict.begin();

	while (it != dict.end())
	{
		//it->first = "xxx";//不允许修改
		//it->second = "xxx";//允许修改
		//cout << *it << " ";//返回pair的引用
		//迭代器重载指针和->
		cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		//编译器进行了优化,第1个箭头是运算符重载,返回pair*,第2个箭头通过pair*返回first或者second
		//cout << it->->first << ":" << it->->second << endl;
		it++;
	}
	cout << endl;
	//不修改
	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}
void test6()
{
	//统计次数,通过一个值找另一个值
	string arr[] = { "苹果","西瓜","苹果","西瓜","苹果","苹果","西瓜","苹果","香蕉" };
	map<string, int> dict;//第1个为key,必须要支持比较大小才可以
	for (auto e : arr)
	{

	}
}
int main()
{
	//test();
	//test1();
	//test2();
	//test4();
	test5();
	return 0;
}