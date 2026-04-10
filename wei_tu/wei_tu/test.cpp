//位图
//给40亿个不重复的无符号整数,没排过序。给一个无符号整数,如何快速判断一个数是否在这40亿个数中。
//1G=1024MB=1024*1024KB=1024*1024*1024Byte=2^30字节
//40亿个数据=160亿字节等于16G左右
//使用set需要存parent等其余的数据,有消耗,需要的空间更多
//2^32个比特位标记对应值在不在
#include"bitmap.h"
#include<bitset>//位图的头文件
void test1()
{
	BitMap::bitmap<1000> bs;
	bs.set(1);
	bs.set(10);
	bs.set(10);
	bs.set(100);
	cout << bs.test(1) << endl;
	cout << bs.test(10) << endl;
	cout << bs.test(100) << endl;
	cout << bs.test(999) << endl << endl;

	bs.reset(100);
	bs.set(999);
	cout << bs.test(100) << endl;
	cout << bs.test(999) << endl;
}
void test2()
{
	//BitMap::bitmap<-1> bs1;
	BitMap::bitmap<0xffffffff> bs;//可以在这行代码添加断点,在任务管理器里面找到wei_tu.exe查看文件内存前后变化了约500MB
	bs.set(1);
	bs.set(10);
	bs.set(10);
	bs.set(100);
}
//给定100亿个整数,设计算法找到只出现一次的整数
//两个位表示量级
void test3()
{
	int a[] = { 1,2,3,3,4,4,4,4,4,2,3,6,3,1,5,5,8,9 };
	BitMap::twobitmap<10> tbs;
	for (auto e : a)
	{
		tbs.set(e);
	}
	for (auto e : a)
	{
		if (tbs.is_once(e))
		{
			cout << e << " ";
		}
	}
	cout << endl;
}
//给两个文件,分别有100亿个整数,我们只有1G内存,如何找到两个文件交集
void test4()
{

}
//位图应用变形:1个文件有100亿个int,1G内存,设计算法找到出现次数不超过2次的所有整数

int main()
{
	//test1();
	//test3();
	test4();
	return 0;
}