//实现一个类，计算程序中创建出了多少个类对象
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A() 
//	{ 
//		++_scount;
//	}
//	A(const A& t) 
//	{ 
//		++_scount;
//	}
//	~A() 
//	{ 
//		--_scount; 
//	}
//	static int GetACount() 
//	{ 
//		return _scount;
//	}
//private:
//	static int _scount;
//};
//int A::_scount = 0;
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}
//
//int main()
//{
//	TestA();
//	return 0;
//}


//求1+2+...+n
//https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//class Solution 
//{
//    class Sum 
//    {
//    public:
//        Sum()
//        {
//            _ret += _i;
//            ++_i;
//        }
//    };
//public:
//    int Sum_Solution(int n) 
//    {
//        Sum arr[n]; //创建n个Sum类型的对象,调用n次构造函数
//        return _ret;
//    }
//private:
//    static int _ret;
//    static int _i;
//};
//int Solution::_ret = 0;
//int Solution::_i = 1;