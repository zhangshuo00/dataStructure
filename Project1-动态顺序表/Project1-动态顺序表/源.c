#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define LIST_INIT_SIZE 100//��ʼ������
#define LISTINCREMENT 10
#define Status int
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define ElemType int

//�ṹ��
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;
//��ʼ��
Status InitList(SqList *L) {
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)
		exit(OVERFLOW);
	L->length = 0;//�ձ���Ϊ0
	L->listsize = LISTINCREMENT;//��ʼ�洢����
	return OK;
}
//����
Status ListInsert(SqList *L, int i, ElemType e) {
	ElemType *p, *q, *newbase;
	if (i<1 || i>L->length + 1) {
		printf("����λ�ò��Ϸ�\n");
		return ERROR;
	}
	if (L->length >= L->listsize) {
		newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			return ERROR;
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	p = &L->elem[i - 1];
	for (q = &L->elem[L->length - 1]; q >= p; --q)
		*(q + 1) = *q;//����λ�ü�֮���Ԫ������
	*p = e;
	++L->length;
	return OK;
}
//ɾ��
Status ListDelete(SqList *L, int i, ElemType *e) {
	if (i<1 || i>L->length) {
		printf("����ʧ�ܣ�ɾ��λ�ô���\n");
		return ERROR;
	}
	*e = L->elem[i - 1];
	for (; i < L->length; ++i) {
		L->elem[i - 1] = L->elem[i];
	}
	--L->length;
	return OK;

}
//ɾ����С
void DeleteMin(SqList *L) {
	int i, Min_i;
	ElemType Min_e = L->elem[0];
	Min_i = 0;
	for (i = 1; i < L->length; ++i) {
		if (L->elem[i] < Min_e) {
			Min_e = L->elem[i];
			Min_i = i;
		}
	}
	ListDelete(L, Min_i + 1, &Min_e);
}
//��ӡ
void ListPrint(SqList L) {
	int i;
	for (i = 0; i < L.length; ++i)
		printf("%d", L.elem[i]);
	printf("\n");
}
