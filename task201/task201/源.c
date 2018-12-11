//任务名:2_1 静态顺序存储线性表的基本实现
//姓名:张朔
//班级:8班
//学号:2017012067
//日期:2018-09-24
#include<stdio.h>
#include<stdlib.h>
#define LIST_INITSIZE 100
#define ElemType int
#define Status int
#define OK 1
#define ERROR 0

typedef struct{
	ElemType elem[LIST_INITSIZE];
	int length;
}SqList;
//链表初始化 
Status InitList(SqList *L){
	L->length=0;
	return OK;
}
//插入 
Status ListInsert(SqList *L,int i,ElemType e){
	//if(i<1||i>L->length+1)
		//return ERROR;
	
	ElemType *q = &(L->elem[i-1]);
	ElemType *p = &(L->elem[L->length-1]);
	for ( ; p>=q; --p) 
	{
		*(p+1) = *p;
	}
	*q = e;	
	++L->length;
	return OK;
}
//打印 
void ListPrint(SqList L){
	int i;
	for(i=0;i<L.length;i++)
	{
		printf("%d\t",L.elem[i]);
	}
	printf("\n");
}
//删除 
Status ListDelete(SqList *L,int i,ElemType *e){
	int j;
	if(i>L->length||i<0||L->length==0)
		return ERROR;
	for(j=i-1;j<L->length;j++)
	{
		L->elem[j]=L->elem[j+1];
	}
	L->length--;
	return OK;
}
//拆分
void DisCreat(SqList L,SqList *B,SqList *C){
	int i;
	int j=0,k=0;
	for(i=0;i<L.length;i++)
	{
		if(L.elem[i]<0)
		{
			B->elem[j]=L.elem[i];
			B->length++;
			j++;
		}
		else
		{
			C->elem[k]=L.elem[i];
			C->length++;
			k++;
		}
	}	
	
} 
//
int main(void)
{
	SqList L;
	SqList B,C;
	int i;
	ElemType e;
	ElemType data[9]={11,-22,33,-3,-88,21,77,0,-9};
	InitList(&L);
	InitList(&B);
	InitList(&C);
	for(i=1;i<=9;i++)
	{
		ListInsert(&L,i,data[i-1]);
	}
	printf("插入完成后L=:\n");
	ListPrint(L);
	
	ListDelete(&L,1,&e);
	printf("删除第一个后L=:\n");
	ListPrint(L);
	
	DisCreat(L,&B,&C);
	printf("拆分L后B=:\n");
	ListPrint(B);
	printf("拆分L后C=:\n");
	ListPrint(C);
	printf("拆分L后L=:\n");
	ListPrint(L);
	
	return 0;
}