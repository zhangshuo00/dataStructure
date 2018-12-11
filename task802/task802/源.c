#include<stdio.h>
#define MAX_VERTEX_NUM 20
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int bool;
typedef int Status;
typedef char VertexType;
//�ṹ��
typedef struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode {
	VertexType data;//������Ϣ
	ArcNode *firstarc;//�ڽ������ͷָ��
}VNode;
typedef struct {
	VNode AdjList[MAX_VERTEX_NUM];//���ͷ���
	int vexnum, arcnum;
}ALGraph;
//
//������:8-2 �ڽӱ�洢ͼ�Ļ�������ʵ��
//����:��˷
//�༶:8��
//ѧ��:2017012067
//����:2018-12-09
//�����ڽӱ�洢������ͼ
bool ALCreateDG(ALGraph *G) {
	int i, j;
	int from, to;
	ArcNode *arc;
	ArcNode *arcn;
	//
	printf("����������ͼ�Ķ�������");
	scanf("%d", &G->vexnum);
	for (i = 0; i < G->vexnum; i++) {
		printf("�����붥�����Ϣ��");
		scanf("%s", &G->AdjList[i].data);
		G->AdjList[i].firstarc = NULL;
	}
	//
	printf("����������ͼ�Ļ�����");
	scanf("%d", &G->arcnum);
	for (j = 0; j < G->arcnum; j++) {
		printf("�����뻡ͷ�ͻ�β��ֵ��");
		scanf("%d %d", &from, &to);
		arc = (ArcNode*)malloc(sizeof(ArcNode));
		arc->nextarc = NULL;
		arc->adjvex = to;
		arcn = G->AdjList[from].firstarc;
		if (!arcn) {
			G->AdjList[from].firstarc = arc;
		}
		else {
			while (arcn->nextarc) {
				arcn = arcn->nextarc;
			}
			arcn->nextarc = arc;
		}
	}
	return OK;
}
//����Ⱥ���
void FindInDegree(ALGraph G, int *indegree) {
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; i++) {
		indegree[i] = 0;
	}
	for (i = 0; i < G.vexnum; i++) {
		p = G.AdjList[i].firstarc;
		while (p != NULL) {
			indegree[p->adjvex]++;
			p = p->nextarc;
		}
	}
	for (i = 0; i < G.vexnum; i++) {
		if (i != G.vexnum - 1)
			printf("%d", indegree[i]);
		else
			printf("%d", indegree[i]);
	}
	return OK;
}
//�ж��Ƿ��л�·
Status TopologicalSort(ALGraph G) {
	ArcNode *p;
	int *indegree;
	int i,j,count=0;
	FindInDegree(G, indegree);
	InitStack(S);
	for (i = 0; i < G.vexnum; i++) {
		if (!indegree[i])
			Push(S, i);
	}
	while (!StackEmpty(S)) {
		Pop(S, i);
		printf("%d %s", i, G.AdjList[i].data);
		count++;
		for (p = G.AdjList[i].firstarc; p; p = p->nextarc) {
			j = p->adjvex;
			if (!(indegree[j]--))
				Push(S, j);
		}
	}
	if (count < G.vexnum)
		printf("������ͼ�л�·");
	else
		printf("������ͼû�л�·");
	return OK;
}



int main(void)
{
	ALGraph G;
	ALCreateDG(&G);
	TopologicalSort(G);

	return 0;
}