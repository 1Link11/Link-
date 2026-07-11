#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAXSIZE 5
/*我们用一个数组，并从头部做一个堆栈，再从尾部做一个堆栈达到双堆栈的效果*/
/*当两个栈的栈顶相遇时表示两个栈都满了*/
struct DStack
{
	int Data[MAXSIZE];/*我们用整形做示范*/
	int top1;
	int top2;
}S={.top1=-1,.top2=MAXSIZE};/*创建DStack结构体S*/
/*双堆栈的存放元素*/
void push(struct DStack* PtrS,int item,int tag)/*tag=1时对第一个栈存放,即tag是区分两个栈的标志*/
{
	if (PtrS->top2 - PtrS->top1 == 1) {/*堆栈满*/
		printf("栈堆满");
		return;
	}
	if (tag == 1)
		PtrS->Data[++(PtrS->top1)] = item;
	else
		PtrS->Data[--(PtrS->top2)] = item;
}
/*双堆栈的删除元素*/
int pop(struct DStack* PtrS, int Tag)/*tag是区分两个栈的标志*/
{
	if (Tag == 1) {
		if (PtrS->top1==-1)/*判断是否空栈*/
		{
			printf("堆栈空");
			return;
		}
		else
			return PtrS->Data[(PtrS->top1)--];
	}
	else
	{
		if (PtrS->top2 == MAXSIZE)
		{
			printf("空栈");
		}
		else
			return PtrS->Data[(PtrS->top2)++];
	}
}
