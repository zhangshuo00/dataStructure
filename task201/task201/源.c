//������:2_1 ��̬˳��洢���Ա�Ļ���ʵ��
//����:��˷
//�༶:8��
//ѧ��:2017012067
//����:2018-09-24
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
//�����ʼ�� 
Status InitList(SqList *L){
	L->length=0;
	return OK;
}
//���� 
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
//��ӡ 
void ListPrint(SqList L){
	int i;
	for(i=0;i<L.length;i++)
	{
		printf("%d\t",L.elem[i]);
	}
	printf("\n");
}
//ɾ�� 
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
//���
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
	printf("������ɺ�L=:\n");
	ListPrint(L);
	
	ListDelete(&L,1,&e);
	printf("ɾ����һ����L=:\n");
	ListPrint(L);
	
	DisCreat(L,&B,&C);
	printf("���L��B=:\n");
	ListPrint(B);
	printf("���L��C=:\n");
	ListPrint(C);
	printf("���L��L=:\n");
	ListPrint(L);
	
	return 0;
}