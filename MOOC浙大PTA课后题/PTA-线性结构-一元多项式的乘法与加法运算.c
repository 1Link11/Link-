#define _CRT_SECURE_NO_WARNINGS 1
/*题目要求*/
/*设计函数分别求两个一元多项式的乘积与和。
输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。*/
/*输入样例:
4 3  4  -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0*/
#include<stdio.h>
#include<stdlib.h>
/*(用链表实现)整体思路如下：我们需要有能读入多项式的函数,把链表各个节点串起的函数，能相乘的函数，能相加的函数，还有输出的函数*/
typedef struct SNode* PtrS;
struct SNode
{
	int xi;
	int zhi;
	PtrS Next;
};
void Attach(int xi, int zhi, PtrS* pRear);
PtrS Read()
{
	int N,zhi,xi;
	PtrS p, t, rear;
	p = (PtrS)malloc(sizeof(struct SNode));
	p->Next = NULL;
	rear = p;
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d", &xi, &zhi);
		Attach(xi, zhi,&rear );/*将当前项插入多项式尾部*/
	}
	t = p;	/*以下三行是在删除临时生成的头节点*/
	p = p->Next;
	free(t);
	return p;
}
void Attach(int xi, int zhi, PtrS* pRear)/*为什么我们用指针的指针？因为c语言是值传递，只有更改地址内的值才能真正修改传入参数的值*/
{
	PtrS P;
	P = (PtrS)malloc(sizeof(struct SNode));
	P->xi = xi;
	P->zhi = zhi;
	P->Next = NULL;
	(*pRear)->Next = P;
	*pRear = P;
}
PtrS Add(PtrS P1, PtrS P2)
{
	PtrS P, p, rear, t;
	P = (PtrS)malloc(sizeof(struct SNode));
	rear = P;
	while (P1 && P2) {
		if (P1->zhi == P2->zhi) {
			if (P1->xi + P2->xi != 0) {
				p = (PtrS)malloc(sizeof(struct SNode));
				p->xi = P1->xi + P2->xi;
				p->zhi = P1->zhi;
				p->Next = NULL;
				rear->Next = p;
				rear = p;
			}
			P1 = P1->Next;
			P2 = P2->Next;
		}	
		else if (P1->zhi > P2->zhi) {
			p = (PtrS)malloc(sizeof(struct SNode));
			p->xi = P1->xi;
			p->zhi = P1->zhi;
			p->Next = NULL;
			rear->Next = p;
			rear = p;
			P1 = P1->Next;
		}
		else
		{
			p = (PtrS)malloc(sizeof(struct SNode));
			p->xi = P2->xi;
			p->zhi = P2->zhi;
			p->Next = NULL;
			rear->Next = p;
			rear = p;
			P2 = P2->Next;
		}
	}
	while (P1 != 0){
		p = (PtrS)malloc(sizeof(struct SNode));
		p->xi = P1->xi;
		p->zhi = P1->zhi;
		p->Next = NULL;
		rear->Next = p;
		rear = p;
		P1 = P1->Next;
	}
	while (P2 != 0) {
		p = (PtrS)malloc(sizeof(struct SNode));
		p->xi = P2->xi;
		p->zhi = P2->zhi;
		p->Next = NULL;
		rear->Next = p;
		rear = p;
		P2 = P2->Next;
	}
	t = P;
	P=P->Next;
	free(t);
	return P;
}
PtrS Mult(PtrS P1, PtrS P2)
{
	if (!P1 || !P2) return NULL;
	PtrS head = (PtrS)malloc(sizeof(struct SNode));
	head->Next = NULL;

	PtrS t1 = P1;
	while (t1) {
		PtrS t2 = P2;
		while (t2) {
			int newXi = t1->xi * t2->xi;
			int newZhi = t1->zhi + t2->zhi;
			PtrS cur = head;
			while (cur->Next && cur->Next->zhi > newZhi)
				cur = cur->Next;
			if (cur->Next && cur->Next->zhi == newZhi) {
				cur->Next->xi += newXi;
				if (cur->Next->xi == 0) {
					PtrS del = cur->Next;
					cur->Next = del->Next;
					free(del);
				}
			}
			else {
				PtrS newNode = (PtrS)malloc(sizeof(struct SNode));
				newNode->xi = newXi;
				newNode->zhi = newZhi;
				newNode->Next = cur->Next;
				cur->Next = newNode;
			}
			t2 = t2->Next;
		}
		t1 = t1->Next;
	}
	PtrS t = head;
	head = head->Next;
	free(t);
	return head;
}
void PrintSNode(PtrS p)
{
	int flag = 0;
	if (!p) {
		printf("0 0\n");
		return;
	}
	while (p) {
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%d %d", p->xi, p->zhi);
		p = p->Next;
	}
	printf("\n");
}
int main()
{
	PtrS P1 = Read();
	PtrS P2 = Read();
	PtrS P3=Add(P1, P2);
	PtrS P4 = Mult(P1, P2);
	PrintSNode(P4);
	PrintSNode(P3);
	return 0;
}