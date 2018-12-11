//任务名:2_2 动态顺序存储线性表的基本实现
//姓名:张朔
//班级:8班
//学号:2017012067
//日期:2018-09-24
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define Status int
#define ElemType int
#define OVERFLOW -1
#define OK 1
#define ERROR 0


typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

//初始化
Status InitList(SqList *L){
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem)
		return OVERFLOW;
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

//插入
Status ListInsert(SqList *L,int i,ElemType e){
	ElemType *q = &(L->elem[i-1]);
	ElemType *p = &(L->elem[L->length-1]);
	ElemType *newbase;
	if(i<1||i>L->length+1)
		return ERROR;
	if(L->length>=LIST_INIT_SIZE)
	{
		newbase = (ElemType *)realloc(L->elem, (LIST_INIT_SIZE + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			return OVERFLOW;
		L->elem = newbase;
		L->listsize = LIST_INIT_SIZE + LISTINCREMENT;
		return OK;

	}
	for ( ; p>=q; --p) 
	{
		*(p+1) = *p;
	}
	*q = e;	
	++L->length;
	return OK;
}
//删除
Status ListDelete(SqList *L,int i,ElemType *e){
	int j;
	//if (i<1 || i>L->length)
		//return ERROR;
	ElemType *p=&(L->elem[i-1]);
	ElemType *q;
	q = &(L->elem[L->length-1]);
	e = p;
	for(++p;p<=q;++p)
	{
		*(p-1)=*p;
	}
	L->length--;
	return OK;
}
//输出打印
void ListPrint(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		printf("%d\t",L.elem[i]);
	}
	printf("\n");
}
//删除最小
void DeleteMin(SqList *L){
	ElemType *q,*p;
	int i=0,j;
	int min = L->elem[0];
	p = &(L->elem[L->length - 1]);
	for ( q= &(L->elem[1]); q <=p; q++)
	{
		i++;
		if (*q < min)
		{
			min = *q;
			j = i;
		}
	}
	ListDelete(L,j+1,&min);
}

int main(void)
{
	SqList L;
	int i;
	ElemType e;
	ElemType data[9] = {11,-22,-33,3,-88,21,77,0,-9};
	InitList(&L);
	for(i=1;i<=9;i++)
	{
		ListInsert(&L,i,data[i-1]);
	}
	printf("插入完成后 L = : \n");
	ListPrint(L);

	ListDelete(&L, 2, &e);
	printf("删除第 2 个后L = : \n");
	ListPrint(L);

	DeleteMin(&L);
	printf("删除L中最小值后L = : \n");
	ListPrint(L);

	DeleteMin(&L);
	printf("删除L中最小值后L = : \n");
	ListPrint(L);

	DeleteMin(&L);
	printf("删除L中最小值后L = : \n");
	ListPrint(L);

	return 0;
}