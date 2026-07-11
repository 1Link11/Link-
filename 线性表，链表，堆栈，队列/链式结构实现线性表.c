#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*创建链表*/
typedef struct LNode* List;
struct LNode {
	int Data;
	List Next;
};
struct LNode L;
List PtrL;
/*求表长*/
int Length(List PtrL)
{
	List p = PtrL;/*p指向表第一个节点*/
	int j = 0;
	while (p) {
		p = p->Next;
		j++;
	}
	return j;
}
/*查找元素的方法一（按序号）*/
List Findkth(int k, List PrtL)
{
	List p = PrtL;
	int i = 1;
	while (p != NULL && i < k) {
		p = p->Next;
		i++;
	}
	if (i == k)
		return p;
	else
		return NULL;
}
/*查找元素的方法二（按值）*/
List Find(int x, List PtrL)
{
	List p = PtrL;
	while (p != NULL && p->Data != x)
		p->Data;
	return p;
}
/*插入*/
List insert(int x, int i, List PtrL)
{
	List p, s;
	if (i == 1) {/*放在链表表头*/
		s = (List)malloc(sizeof(struct LNode));
		s->Data = x;
		s->Next = PtrL;
	}
	p = Findkth(i - 1, PtrL);/*通过我们定义的元素来寻找插入的地点*/
	if (p == NULL) {
		printf("参数i不对");
		return NULL;
	}
	else{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = x;
		s->Next = p->Next;
		p->Next = s;
		return PtrL;
	}
}
/*删除*/
List Delete(int i, List PtrL)
{
	List p, s;
	if (i == 1) {/*先判断是不是删除第一位元素*/
		s = PtrL;
		if (PtrL != NULL)/*先判断下头元素是不是没有装填元素*/
			PtrL = PtrL->Next;
		else
			return NULL;
		free(s);
		return PtrL;
	}
	p = Findkth(i - 1, PtrL);
	if (p == NULL) {
		printf("第%d个节点不存在，i-1");
		return NULL;
	}
	else if (p->Next == NULL) {
		printf("第%d个节点不存在，i");
	}
	else
	{
		s = p->Next;	  /*s指向第i个节点*/
		p->Next = s->Next;/*将p从链表中抹除*/
		free(s);
		return PtrL;
	}
		
}