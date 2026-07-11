#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAXSIZE 5
typedef struct SNode* stack;
struct SNode
{
	int Data[MAXSIZE];
	int top;
};
/*ÈëÕ»*/
void Push(stack PtrS, int item)
{
	if (PtrS->top == MAXSIZE - 1) {
		printf("¶ÑÕ»Âú");
		return;
	}
	else
	{
		PtrS->Data[++(PtrS->top)] = item;
		return;
	}
}
/*³öÕ»*/
int pop(stack PtrS)
	{
	if (PtrS->top == -1) {
		printf("¿ÕÕ»");
		return ERROR;
	}
	else
		return(PtrS->Data[(PtrS->top)--]);
}
