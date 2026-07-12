#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAXSIZE 5
/*堆栈结构类似叠盘子。后进先出*/
typedef struct SNode* stack;
struct SNode
{
	int Data[MAXSIZE];
	int top;
};
/*入栈*/
void Push(stack PtrS, int item)
{
	if (PtrS->top == MAXSIZE - 1) {		 /*先判断栈是否满了*/
		printf("堆栈满");				 
		return;							 
	}                                    
	else                                 
	{                                    
		PtrS->Data[++(PtrS->top)] = item;/*这里实际上实现了两个操作，首先将top往前进一位，再往里赋值，简化了代码*/
		return;
	}
}
/*出栈*/
int pop(stack PtrS)
	{
	if (PtrS->top == -1) {
		printf("空栈");
		return -1;
	}
	else
		return(PtrS->Data[(PtrS->top)--]);/*以当前top下标读取数组元素后top值自减并更新*/
}
