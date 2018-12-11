#include<stdio.h>
#define MAX_VERTEX_NUM 20
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int bool;
typedef int Status;
typedef char VertexType;
//结构体
typedef struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode {
	VertexType data;//顶点信息
	ArcNode *firstarc;//邻接链表的头指针
}VNode;
typedef struct {
	VNode AdjList[MAX_VERTEX_NUM];//存放头结点
	int vexnum, arcnum;
}ALGraph;
//
//任务名:8-2 邻接表存储图的基本操作实现
//姓名:张朔
//班级:8班
//学号:2017012067
//日期:2018-12-09
//创建邻接表存储的有向图
bool ALCreateDG(ALGraph *G) {
	int i, j;
	int from, to;
	ArcNode *arc;
	ArcNode *arcn;
	//
	printf("请输入有向图的顶点数：");
	scanf("%d", &G->vexnum);
	for (i = 0; i < G->vexnum; i++) {
		printf("请输入顶点的信息：");
		scanf("%s", &G->AdjList[i].data);
		G->AdjList[i].firstarc = NULL;
	}
	//
	printf("请输入有向图的弧数：");
	scanf("%d", &G->arcnum);
	for (j = 0; j < G->arcnum; j++) {
		printf("请输入弧头和弧尾的值：");
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
//求入度函数
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
//判断是否有回路
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
		printf("该有向图有回路");
	else
		printf("该有向图没有回路");
	return OK;
}



int main(void)
{
	ALGraph G;
	ALCreateDG(&G);
	TopologicalSort(G);

	return 0;
}