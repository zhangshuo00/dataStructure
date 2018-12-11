#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define LIST_INIT_SIZE 100//初始分配量
#define LISTINCREMENT 10
#define Status int
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define ElemType int

//结构体
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;
//初始化
Status InitList(SqList *L) {
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)
		exit(OVERFLOW);
	L->length = 0;//空表长度为0
	L->listsize = LISTINCREMENT;//初始存储容量
	return OK;
}
//插入
Status ListInsert(SqList *L, int i, ElemType e) {
	ElemType *p, *q, *newbase;
	if (i<1 || i>L->length + 1) {
		printf("插入位置不合法\n");
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
		*(q + 1) = *q;//插入位置及之后的元素右移
	*p = e;
	++L->length;
	return OK;
}
//删除
Status ListDelete(SqList *L, int i, ElemType *e) {
	if (i<1 || i>L->length) {
		printf("操作失败，删除位置错误\n");
		return ERROR;
	}
	*e = L->elem[i - 1];
	for (; i < L->length; ++i) {
		L->elem[i - 1] = L->elem[i];
	}
	--L->length;
	return OK;

}
//删除最小
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
//打印
void ListPrint(SqList L) {
	int i;
	for (i = 0; i < L.length; ++i)
		printf("%d", L.elem[i]);
	printf("\n");
}
