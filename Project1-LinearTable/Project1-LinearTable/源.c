#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define LIST_INITSIZE 100
#define ElemType int
#define Status int 
#define OK 1
#define ERROR 0
//����ṹ��
typedef struct{
	ElemType elem[LIST_INITSIZE];
	int length;
}SqList;
//��ʼ��
Status InitList(SqList *L) {
	L->length = 0;
	return OK;
}
//����
Status ListInsert(SqList *L,int i,ElemType e) {
	ElemType *p, *q;
	if (i<1 || i>L->length + 1) {
		printf("����ʧ�ܣ��������λ��");
		return ERROR;
	}
	if (L->length >= LIST_INITSIZE) {
		printf("����ʧ�ܣ�˳�������");
		return ERROR;
	}
	p = &L->elem[i - 1];
	for (q = &L->elem[L->length - 1]; q >= p; --q) {
		*(q + 1) = *q;
	}
	*p = e;
	++L->length;
	return OK;  
}
//���
void DidCreat(SqList A, SqList *B, SqList *C) {
	int i;
	for (i = 0; i < A.length; ++i) {
		if (A.elem[i] < 0) {
			ListInsert(B, B->length + 1, A.elem[i]);
		}
		else {
			ListInsert(C, C->length + 1, C->elem[i]);
		}
	}
}
//�����ӡ
void ListPrint(SqList L) {
	int i;
	for (i = 0; i < L.length; ++i) {
		printf("%d", L.elem[i]);
	}
	printf("\n");
}
