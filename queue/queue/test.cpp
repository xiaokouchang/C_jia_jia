#include"queue.h"
using namespace que;
int main()
{
	queue<int, vector<int>> q1;//Ð§ÂÊµÍ
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	while (!q1.empty())
	{
		cout << q1.front() << " ";
		q1.pop();
	}
	cout << endl;
	queue<int, list<int>> q2;
	q2.push(1);
	q2.push(2);
	q2.push(3);
	q2.push(4);
	while (!q2.empty())
	{
		cout << q2.front() << " ";
		q2.pop();
	}
	cout << endl;
	return 0;
}