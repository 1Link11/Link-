#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 5
#include<stdio.h>
#include<stdlib.h>
/*队列和排队一样，后进先出*/
typedef struct QNode* Queue;
struct QNode {
	int Data[MAXSIZE];
	int rear;		/*rear记录队尾元素位置*/
	int front;		/*front记录队列头元素位置*/
};
/*入队列*/
void addQ(Queue PtrQ, int item)
{
	if ((PtrQ->rear + 1) % MAXSIZE == PtrQ->front) {/*通过加一取余的方法实现循环利用数组空间*/
		{
			printf("队列满");
			return;
		}
	}
	else {
		PtrQ->rear = (PtrQ->rear + 1) % MAXSIZE;
		PtrQ->Data[PtrQ->rear] = item;
		return;
	}
}
/*出队列*/
int DelectQ(Queue PtrQ)
{
	if (PtrQ->front == PtrQ->rear) {
		printf("队列为空");
		return -1;
	}
	else
	{
		PtrQ->front = (PtrQ->front + 1) % MAXSIZE;
		return PtrQ->Data[PtrQ->front];
	}
}
