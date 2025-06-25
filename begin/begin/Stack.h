#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//namespace N2
//{
//	int x = 0;
//}

struct stack
{
	int* a;
	int top;
	int capacity;
};


void StackInit(struct stack* pst, int defaultCapacity = 4);