#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
/*事实上就是一个单链表*/
typedef struct SNode* Stack;
struct SNode {
	int Data;
	struct SNode* Next;
};
/*创建栈的一个节点*/
Stack CreateStack()
{/*构建堆栈头节点返回指针*/
	Stack s;
	s = (Stack)malloc(sizeof(struct SNode));
	s->Next = NULL;
	return s;
}
/*判断栈是否为空*/
int IsEmpty(Stack s)
{
	return(s->Next == NULL);/*空了返回1，否则返回0*/
}
/*将元素item压入栈中*/
void push(int item,Stack s)
{
	struct SNode* Tmpcell;
	Tmpcell = (Stack)malloc(sizeof(struct SNode));
	Tmpcell->Data = item;
	Tmpcell->Next = s->Next;
	s->Next = Tmpcell;
}
/*删除栈顶元素*/
int pop(Stack s)
{
	Stack firstcell;
	int topdata;
	if (IsEmpty(s)) {
		printf("堆栈空");
		return -1;
	}	
	else {
		firstcell = s->Next;
		s->Next = firstcell->Next;
		topdata = firstcell->Data;
		free(firstcell);
		return topdata;
	}
}