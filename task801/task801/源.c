#include<stdio.h>
#define INFINITY 0
#define MAX_VERTEX_NUM 20 //最大顶点个数
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int bool;
typedef int VRType;
typedef int InfoType;
typedef char VertexType;

typedef struct ArcCell {
	VRType adj;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];//顶点向量
	AdjMatrix arcs;//邻接矩阵
	int vexnum, arcnum;//顶点数和边数
	int visited[MAX_VERTEX_NUM];
}MGraph;
//
//任务名:8-1 图的邻接矩阵存储基本操作实现
//姓名:张朔
//班级:8班
//学号:2017012067
//日期:2018-12-09
bool CreateUDG(MGraph *G) {
	int i,j;
	printf("请输入无向图的顶点数和边数：");
	scanf("%d,%d",&G->vexnum, &G->arcnum);
	printf("请输入顶点向量：");
	for (i = 0; i < G->vexnum; i++) {
		scanf("%s",&G->vexs[i]);
	}
	//初始化
	for (i = 0; i < G->vexnum; i++) {
		for (j = 0; i < G->arcnum; j++)
			G->arcs[i][j].adj = INFINITY;
	}
	//构造邻接矩阵
	for (int k = 0; k < G->arcnum; k++) {
		char v1, v2;
		int w;
		printf("请输入一条边依附的两个顶点以及权值:");
		scanf("%s,%s,%d", &v1, &v2, &w);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G->arcs[i][j].adj = w;
		G->arcs[j][i].adj = G->arcs[i][j].adj;
	}
	return OK;
}

//判断无向图的连通性
void JudgeUDGConnectivity(MGraph G) {
	int i, j,count;
	//标识数组初始化
	for (i = 0; i < G.vexnum; i++) {
		G.visited[i] = 0;
	}
	//深度优先遍历
	for (i = 0; i < G.vexnum; i++) {
		if (!G.visited[i]) {
			DFS(G, i);
		}
	}
	for (j = 0; j < G.vexnum; j++) {
		if (G.visited[j] == 1) {
			count++;
		}
	}
	if (count == G.vexnum)
		printf("该图为连通图！");
	else
		printf("该图为非连通图！");
	return OK;
}
//DFS
void DFS(MGraph G, int v) {
	G.visited[v] = 1;
	for (int i = 0; i < G.vexnum; i++) {
		if (G.arcs[v][i].adj != 0 && !G.visited[i]) {
			DFS(G, i);
		}
	}
	return OK;
}
//定位边在邻接矩阵中的位置
bool LocateVex(MGraph *G, char v) {
	int i;
	for (i = 0; i < G->vexnum; i++) {
		if (G->vexs[i] == v) {
			break;
		}
	}
	return i;
}




int main(void)
{
	MGraph G;
	CreateUDG(&G);
	JudgeUDGConnectivity(G);

	return 0;
}