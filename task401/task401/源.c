//������:4_1 �����ж�
//����:��˷
//�༶:8��
//ѧ��:2017012067
//����:2018-10-25

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define SElemType char
#define QElemType char
#define Status int
#define OVERFLOW -1
#define OK 1
#define ERROR 0

typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//����ն���Q
Status InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

//����Ԫ��eΪQ�Ķ�βԪ��
Status EnQueue(LinkQueue &Q,QElemType e){
	QueuePtr p,q;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;

}

//ɾ��Q�Ķ�ͷԪ��
Status DeQueue(LinkQueue &Q,QElemType &e){
	QueuePtr p;
	if(Q.front == Q.rear) return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p) Q.rear = Q.front;
	free(p);
	return OK;
}


typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

//ջ�ĳ�ʼ��
Status InitStack(SqStack &S){
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status JudgeNull(SqStack S){
	if(S.top==0){
		return 0;
	}else{
		return 1;
	}
}
//��e����S��ջ��Ԫ��
Status GetTop(SqStack S,SElemType &e){
	if(S.top == S.base)
		return ERROR;
	else{
		e = *(S.top-1);
		return OK;
	}

}
//����Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(SqStack &S,SElemType e){
	if(S.top - S.base >= S.stacksize){
		S.base = (SElemType *)realloc(S.base,(S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}
//ɾ��ջ��Ԫ�أ�����e������ֵ
Status Pop(SqStack &S,SElemType &e){
	if(S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}
//�ж��Ƿ�Ϊ����
Status JudgingPalindrome(char c[]){
	LinkQueue Q;
	SqStack S;
	SElemType a;
	QElemType b;
	int i =0;
	while(c[i] != '@'){
		Push(S,c[i]);
		EnQueue(Q,c[i++]);
	}
	for(i;i>0;i--){
		Pop(S,a);
		DeQueue(Q,b);
		if(a != b) return ERROR;
	}
	return OK;
}


int main(void){
	char *a[20];
	LinkQueue *q;
	SqStack *s;
	InitStack(*s);
	InitQueue(*q);
	printf("������һ���ַ���������@����\n");
	for(int i =0;i<20;i++){
		scanf("%c",a[i]);
	}
	JudgingPalindrome(a[20]);

}
//������:4_3 ������ݹ�
//����:��˷
//�༶:8��
//ѧ��:2017012067
//����:2018-10-25
void digui(int i){
	if(i>1){
		printf("%d",i);
		digui(i-1);
	}
	return ;
}

//������:4_4 ѭ������
//����:��˷
//�༶:8��
//ѧ��:2017012067
//����:2018-10-25

#define OK 
#define ERROR 
typedef int Styo;
typedef struct{
	Styo *p;
	int front;
	int rear;
	int tag;
}Styu;
void EnQueue(Styu *q,Styo n){
	if((*q).rear == (*q).front && (*q).tag == 1)
		return ERROR;
	(*q).base[(*q).rear] = n;
	(*q).rear = ((*q).rear + 1)%MAXQSIZE;
	if((*q).rear == (*q).front)
		(*q).tag = 1;
	return OK;
}
void DeQueue(Styu *q,Styo n){
	if((*q).front == (*q).rear && (*q).tag == 0)
		return ERROR;
	*n = (*q).base[(*q).front];
	(*q).front = ((*q).front+1)%NAXQSIZE;
	if((*q).rear == (*q).front)
		(*q).tag = 0;
	return OK;
}