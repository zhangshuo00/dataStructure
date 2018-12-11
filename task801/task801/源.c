#include<stdio.h>
#define INFINITY 0
#define MAX_VERTEX_NUM 20 //��󶥵����
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
	VertexType vexs[MAX_VERTEX_NUM];//��������
	AdjMatrix arcs;//�ڽӾ���
	int vexnum, arcnum;//�������ͱ���
	int visited[MAX_VERTEX_NUM];
}MGraph;
//
//������:8-1 ͼ���ڽӾ���洢��������ʵ��
//����:��˷
//�༶:8��
//ѧ��:2017012067
//����:2018-12-09
bool CreateUDG(MGraph *G) {
	int i,j;
	printf("����������ͼ�Ķ������ͱ�����");
	scanf("%d,%d",&G->vexnum, &G->arcnum);
	printf("�����붥��������");
	for (i = 0; i < G->vexnum; i++) {
		scanf("%s",&G->vexs[i]);
	}
	//��ʼ��
	for (i = 0; i < G->vexnum; i++) {
		for (j = 0; i < G->arcnum; j++)
			G->arcs[i][j].adj = INFINITY;
	}
	//�����ڽӾ���
	for (int k = 0; k < G->arcnum; k++) {
		char v1, v2;
		int w;
		printf("������һ�������������������Լ�Ȩֵ:");
		scanf("%s,%s,%d", &v1, &v2, &w);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G->arcs[i][j].adj = w;
		G->arcs[j][i].adj = G->arcs[i][j].adj;
	}
	return OK;
}

//�ж�����ͼ����ͨ��
void JudgeUDGConnectivity(MGraph G) {
	int i, j,count;
	//��ʶ�����ʼ��
	for (i = 0; i < G.vexnum; i++) {
		G.visited[i] = 0;
	}
	//������ȱ���
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
		printf("��ͼΪ��ͨͼ��");
	else
		printf("��ͼΪ����ͨͼ��");
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
//��λ�����ڽӾ����е�λ��
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