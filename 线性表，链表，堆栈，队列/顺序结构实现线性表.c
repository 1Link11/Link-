#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAXSISE 5
/*创建线性表*/
typedef struct LNode* List;/*指向结构体的指针List*/
struct LNode			   /*创建结构体包含整型数组存放数据，以及最后一位元素下标last*/
{
	int Data[MAXSISE];
	int Last;
};
struct LNode L;			   /*创建LNode结构体元素L*/
List PtrL;				   /*创建指向结构体LNode指针PtrL*/
/*初始化线性表*/
List MakeEmptyList(void)
{
	List PtrL;             /*指向结构体指针*/
	PtrL = (List)malloc(sizeof(struct LNode));/*用malloc函数分配一块空间，创造LNode结构体，并用PtrL指向那块内存空间 */
	PtrL->Last = -1;		   /*创建空表，令最后一项元素下标等于-1*/
}
/*查找线性表元素*/
int Find(int K, List PtrL)
{
	int i=0;
	while (i <= PtrL->Last && PtrL->Data[i] != K)/*前一项令i在数组里寻找，超出数组长度即找不到，后一项看数组元素和寻找元素是否相等*/
		i++;
	if (i > PtrL->Data)
		return -1;
	else
		return i;
}
/*插入实现*/
void insert(int X,int i, List PtrL)
{
	int j;
	if (PtrL->Last == MAXSISE - 1) {/*先判断表还有没有空间*/
		printf("表满");
		return;
	}
	if (i<1 || i>PtrL->Last + 2)/*i不能大于等于数组目前最大元素后两位*/
		printf("位置不合法");
	for (j = PtrL->Last; j > i - 1; j--)
		PtrL->Data[j + 1] = PtrL->Data[j];/*将数组元素倒序向后移动*/
	PtrL->Data[i - 1] = X;
	PtrL->Last++;
	return;
}
/*删除实现*/
void Delete(int i, List PtrL)
{
	int j;
	if (i<1 || i>PtrL->Last + 1) {
		printf("位置不合法,");
		return;
	}
	for (j = i; j < PtrL->Last; j++)
		PtrL->Data[j - 1] = PtrL->Data[j];/*数组元素顺序向前移动*/
	PtrL->Last--;
	return;
}