//任务名:4_1 回文判断
//姓名:张朔
//班级:8班
//学号:2017012067
//日期:2018-10-25

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

//构造空队列Q
Status InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

//插入元素e为Q的队尾元素
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

//删除Q的对头元素
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

//栈的初始化
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
//用e返回S的栈顶元素
Status GetTop(SqStack S,SElemType &e){
	if(S.top == S.base)
		return ERROR;
	else{
		e = *(S.top-1);
		return OK;
	}

}
//插入元素e为新的栈顶元素
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
//删除栈顶元素，并用e返回其值
Status Pop(SqStack &S,SElemType &e){
	if(S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}
//判断是否为回文
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
	printf("请输入一个字符串：并以@结束\n");
	for(int i =0;i<20;i++){
		scanf("%c",a[i]);
	}
	JudgingPalindrome(a[20]);

}
//任务名:4_3 递推与递归
//姓名:张朔
//班级:8班
//学号:2017012067
//日期:2018-10-25
void digui(int i){
	if(i>1){
		printf("%d",i);
		digui(i-1);
	}
	return ;
}

//任务名:4_4 循环队列
//姓名:张朔
//班级:8班
//学号:2017012067
//日期:2018-10-25

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