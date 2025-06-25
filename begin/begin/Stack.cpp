#define _CRT_SECURE_NO_WARNINGS 1 

#include "Stack.h"

void StackInit(struct stack* pst, int defaultCapacity)
{
	pst->a = (int*)malloc(sizeof(int) * defaultCapacity);
	if (pst->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	pst->top = 0;
	pst->capacity = 4;
}
