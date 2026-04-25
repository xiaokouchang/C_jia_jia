//#include<iostream>
//#include<stack>
//#include<queue>
//using namespace std;
//void test_stack_queue()
//{
//	stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//	queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//}
//int main()
//{
//	test_stack_queue();
//	string s1("+");
//	string s2("+");
//	printf("%p\n", s1);
//	printf("%p\n", s2);
//	return 0;
//}


#include"stack.h"
using namespace sta;
int main()
{
	stack<int, vector<int>> st1;
	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(4);
	while (!st1.empty())
	{
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;
	stack<int, list<int>> st2;
	st2.push(1);
	st2.push(2);
	st2.push(3);
	st2.push(4);
	while (!st2.empty())
	{
		cout << st2.top() << " ";
		st2.pop();
	}
	cout << endl;
	return 0;
}


