#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef char SElemType;//��׼��ջ��ʹ��

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}OPTR;//�������ַ����е�ջ

typedef struct QNode {
	char data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}Linkqueue;
//����һ������ַ����е�ջ
Status Initoptr(OPTR p) {
	p.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!p.base)
		exit(OVERFLOW);
	p.top = p.base;
	p.stacksize = STACK_INIT_SIZE;
	return OK;
}
//��ջ��Ϊ����ɾ��ջ��Ԫ�أ���e��������ֵ
Status Popq(OPTR p, char e) {
	if (p.top == p.base)
		return ERROR;
	e = *--p.top;
	return OK;
}

Status Pushq(OPTR p, char e) {
	if (p.top - p.base >=         p.stacksize) {//ջ��׷�ӿռ�
		p.base = (char *)realloc(p.base, (p.stacksize + STACKINCREMENT) * sizeof(char));
		if (!p.base)exit(OVERFLOW);
		p.top = p.base + p.stacksize;
		p.stacksize += STACKINCREMENT;
	}
	*p.top++ = e;
	return OK;
}


//����һ������ַ����еĶ���
Status InitQueue(Linkqueue Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}
//�����βԪ��
Status EnQueue(Linkqueue Q, char e) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
//�����в�Ϊ����ɾ����ͷԪ��
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