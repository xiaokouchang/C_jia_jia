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


//最小栈
//https://leetcode.cn/problems/min-stack/description/
//方法1
//class MinStack 
//{
//public:
//    MinStack() 
//    {
//        _min.push(INT_MAX);
//    }
//    void push(int val) 
//    {
//        _st.push(val);
//        _min.push(min(val, _min.top()));
//    }
//    void pop() 
//    {
//        _min.pop();
//        _st.pop();
//    }
//    int top() 
//    {
//        return _st.top();
//    }
//    int getMin() 
//    {
//        return _min.top();
//    }
//private:
//    stack<int> _st;
//    stack<int> _min;
//};


//方法2
//class MinStack 
//{
//public:
//    MinStack()
//    {
//    }
//    void push(int val) 
//    {
//        _st.push(val);
//        if (_min.empty() || val <= _min.top())
//        {
//            _min.push(val);
//        }
//    }
//    void pop() 
//    {
//        if (_st.top() == _min.top())
//        {
//            _min.pop();
//        }
//        _st.pop();
//    }
//    int top() 
//    {
//        return _st.top();
//    }
//    int getMin()
//    {
//        return _min.top();
//    }
//private:
//    stack<int> _st;
//    stack<int> _min;
//};


//方法3
//pair
//class MinStack
//{
//public:
//    MinStack() 
//    {
//    }
//    void push(int x) 
//    {
//        if (st.size() == 0)
//        {
//            st.push({ x, x });
//        }
//        else
//        {
//            st.push({ x, min(x, st.top().second) });
//        }
//    }
//    void pop() 
//    {
//        st.pop();
//    }
//    int top() 
//    {
//        return st.top().first;
//    }
//    int getMin()
//    {
//        return st.top().second;
//    }
//private:
//    stack<pair<int, int>> st;
//};


//方法4(改进方法3)
//class MinStack 
//{
//public:
//    MinStack()
//    {
//        _st.push({ 0,INT_MAX });
//    }
//
//    void push(int val)
//    {
//        _st.push({ val,min(val,getMin()) });
//    }
//
//    void pop() 
//    {
//        _st.pop();
//    }
//
//    int top() {
//        return _st.top().first;
//    }
//
//    int getMin() {
//        return _st.top().second;
//    }
//private:
//    stack<pair<int, int>> _st;
//};


//方法5
//不许另外借助辅助栈
//class MinStack 
//{
//private:
//    // 存储差值的栈,使用long long避免int溢出
//    stack<long long> data;
//    // 记录当前栈的最小值
//    long long minVal;
//public:
//    MinStack() {}
//    // 入栈
//    void push(int val) 
//    {
//        if (data.empty()) 
//        {
//            // 栈空时，差值为0，最小值为当前值
//            data.push(0LL);
//            minVal = val;
//        }
//        else
//        {
//            // 计算当前值与最小值的差值
//            long long diff = (long long)val - minVal;
//            data.push(diff);
//            // 差值为负，说明当前值是新的最小值
//            if (diff < 0)
//            {
//                minVal = val;
//            }
//        }
//    }
//
//    // 出栈
//    void pop() 
//    {
//        if (data.empty()) return; //防止空栈
//        long long topVal = data.top();
//        data.pop();
//        // 弹出的是最小值节点,还原上一个最小值
//        if (topVal < 0) 
//        {
//            minVal = minVal - topVal;
//        }
//    }
//    //获取栈顶元素
//    int top() 
//    {
//        if (data.empty()) return -1; //防止空栈
//        long long topDiff = data.top();
//        //差值<0:真实值就是最小值;否则最小值+差值
//        return topDiff < 0 ? (int)minVal : (int)(minVal + topDiff);
//    }
//    // 获取最小值
//    int getMin() 
//    {
//        return (int)minVal;
//    }
//};


