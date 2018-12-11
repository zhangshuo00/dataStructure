#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define ElemType int 
#define Status int

typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList(SqList &L){
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	
}
