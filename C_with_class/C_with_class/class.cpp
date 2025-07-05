#define _CRT_SECURE_NO_WARNINGS 1 
#include "class.h"
void Stack::Init(int defaultCapacity)//类里面成员函数的定义
{
	a = (int*)malloc(sizeof(int) * capacity);
	if (nullptr == a)
	{
		perror("malloc fail");
		return;
	}
	capacity = defaultCapacity;
	top = 0;
}