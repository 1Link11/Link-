#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int Data;
	struct Node* Next;
};
struct QNode
{
	struct Node* front;
	struct Node* rear;
};
typedef  struct QNode* Queue;
Queue PtrQ;
/*不带头节点出队操作*/
int DeleteQ(Queue PtrQ)
{
	struct Node* Frontcell;
	int FrontData;
	if (PtrQ->front = NULL) {
		print("队列空");
		return -1;
	}
	Frontcell = PtrQ->front;
	if (PtrQ->front == PtrQ->rear)/*当队列只有一个元素时*/
		PtrQ->front = PtrQ->rear = NULL;
	else
		PtrQ->front = PtrQ->front->Next;
	FrontData = Frontcell->Data;
	free(Frontcell);
	return FrontData;
}
