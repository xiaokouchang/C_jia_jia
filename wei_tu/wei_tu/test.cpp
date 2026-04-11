//位图
//给40亿个不重复的无符号整数,没排过序。给一个无符号整数,如何快速判断一个数是否在这40亿个数中。
//1G=1024MB=1024*1024KB=1024*1024*1024Byte=2^30字节
//40亿个数据=160亿字节等于16G左右
//使用set需要存parent等其余的数据,有消耗,需要的空间更多
//2^32个比特位标记对应值在不在
#include"bitmap.h"
#include<bitset>//位图的头文件
//void test1()
//{
//	BitMap::bitmap<1000> bs;
//	bs.set(1);
//	bs.set(10);
//	bs.set(10);
//	bs.set(100);
//	cout << bs.test(1) << endl;
//	cout << bs.test(10) << endl;
//	cout << bs.test(100) << endl;
//	cout << bs.test(999) << endl << endl;
//
//	bs.reset(100);
//	bs.set(999);
//	cout << bs.test(100) << endl;
//	cout << bs.test(999) << endl;
//}
//void test2()
//{
//	//BitMap::bitmap<-1> bs1;
//	BitMap::bitmap<0xffffffff> bs;//可以在这行代码添加断点,在任务管理器里面找到wei_tu.exe查看文件内存前后变化了约500MB
//	bs.set(1);
//	bs.set(10);
//	bs.set(10);
//	bs.set(100);
//}
////给定100亿个整数,设计算法找到只出现一次的整数
////两个位表示量级
//void test3()
//{
//	int a[] = { 1,2,3,3,4,4,4,4,4,2,3,6,3,1,5,5,8,9 };
//	BitMap::twobitmap<10> tbs;
//	for (auto e : a)
//	{
//		tbs.set(e);
//	}
//	for (auto e : a)
//	{
//		if (tbs.is_once(e))
//		{
//			cout << e << " ";
//		}
//	}
//	cout << endl;
//}
////给两个文件,分别有100亿个整数,我们只有1G内存,如何找到两个文件交集
////思路1
////1个文件所有值映射到1个位图,另一个文件判断在不在,出来的交集还需要再次去重
////思路2
////两个文件分别映射到2个位图,对应位置与一下
//void test4()
//{
//	//没有负数
//	//int a1[] = { 1,2,3,3,4,4,4,4,4,2,3,6,3,1,5,5,8,9 };
//	//int a2[] = { 1,8,4,4,8,4,1,1,1,1 };
//	//BitMap::bitmap<10> bs1;
//	//BitMap::bitmap<10> bs2;
//	////去重
//	//for (auto e : a1)
//	//{
//	//	bs1.set(e);
//	//}
//	////去重
//	//for (auto e : a2)
//	//{
//	//	bs2.set(e);
//	//}
//	//for (size_t i = 0; i < 10; i++)
//	//{
//	//	if (bs1.test(i) && bs2.test(i))
//	//	{
//	//		cout << i << " ";
//	//	}
//	//}
//	//cout << endl;
//	//负数
//	//相对映射
//	//-1-->0,-2-->1
//	//int a1[] = { -1,2,3,3,4,4,4,4,4,2,3,6,3,1,5,5,8,9 };
//	//int a2[] = { -1,8,4,4,8,4,1,1,1,1 };
//	//BitMap::bitmap<10> bs1;
//	//BitMap::bitmap<10> bs2;
//	////去重
//	//for (auto e : a1)
//	//{
//	//	bs1.set(e);
//	//}
//	////去重
//	//for (auto e : a2)
//	//{
//	//	bs2.set(e);
//	//}
//	//for (size_t i = 0; i < -1; i++)
//	//{
//	//	if (bs1.test(i) && bs2.test(i))
//	//	{
//	//		cout << i << " ";
//	//	}
//	//}
//	//cout << endl;
//	
//
//}
////位图应用变形:1个文件有100亿个int,1G内存,设计算法找到出现次数不超过2次的所有整数
////类似问题1,两个位图解决
////00
////01 1次
////10 2次
////11 2次以上
//int main()
//{
//	//test1();
//	//test3();
//	test4();
//	return 0;
//}


