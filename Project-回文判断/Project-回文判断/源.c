#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef char SElemType;//标准化栈的使用

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}OPTR;//定义存放字符序列的栈

typedef struct QNode {
	char data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}Linkqueue;
//构造一个存放字符序列的栈
Status Initoptr(OPTR p) {
	p.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!p.base)
		exit(OVERFLOW);
	p.top = p.base;
	p.stacksize = STACK_INIT_SIZE;
	return OK;
}
//若栈不为空则删除栈顶元素，用e返回其他值
Status Popq(OPTR p, char e) {
	if (p.top == p.base)
		return ERROR;
	e = *--p.top;
	return OK;
}

Status Pushq(OPTR p, char e) {
	if (p.top - p.base >=         p.stacksize) {//栈满追加空间
		p.base = (char *)realloc(p.base, (p.stacksize + STACKINCREMENT) * sizeof(char));
		if (!p.base)exit(OVERFLOW);
		p.top = p.base + p.stacksize;
		p.stacksize += STACKINCREMENT;
	}
	*p.top++ = e;
	return OK;
}


//构造一个存放字符序列的队列
Status InitQueue(Linkqueue Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}
//插入队尾元素
Status EnQueue(Linkqueue Q, char e) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
//若队列不为空则删除队头元素
Status DeQueue(Linkqueue Q, char e) {
	QueuePtr p;
	if (Q.front == Q.rear)return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}