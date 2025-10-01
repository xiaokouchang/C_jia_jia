#include<iostream>
#include<queue>
using namespace std;
void test()
{
	//priority_queue<int, deque<int>, greater<int>> pq;

	//Ð¡¶Ñ
	priority_queue<int, vector<int>,greater<int>> pq;
	
	//´ó¶Ñ
	//priority_queue<int> pq;

	pq.push(3);
	pq.push(5);
	pq.push(1);
	pq.push(4);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main()
{
	test();
	return 0;
}