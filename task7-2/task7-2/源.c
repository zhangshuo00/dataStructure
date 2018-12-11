//任务名:7-2
//姓名:张朔
//班级:8班
//学号:2017012067
//日期:2018-11-24
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int TElemType ;
typedef int Status;

//结构体
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//创建二叉链表表示的二叉树
Status CreateBiTree(BiTree T){
	TElemType ch;
	scanf("%d",&ch);
	if(ch == -1){
		T = NULL;
	}else{
		T = (BiTree)malloc(sizeof(BiTNode));
		if(!T){
			exit(-1);
		}
		T->data = ch;
		printf("输入%d的左子结点：",ch);
		CreateBiTree(T->lchild);
		printf("输入%d的右子结点：",ch);
		CreateBiTree(T->rchild);
	}
	return 1;
}
//计算二叉树的深度
Status BT_Depth(BiTree T){
	int ldepth = 0;
	int rdepth = 0;
	if(T == NULL)
		return 0;
	else {
		ldepth = BT_Depth(T->lchild);
		rdepth = BT_Depth(T->rchild);
	}
	if(ldepth>rdepth)
		return ldepth++;
	else
		return rdepth++;
}
//
int main(void){
	BiTNode *root = NULL;
	int depth = 0;
	CreateBiTree(root);
}

//任务名:7-3
//姓名:张朔
//班级:8班
//学号:2017012067
//日期:2018-11-24
#include<stdio.h>
#include<malloc.h>

typedef char TElemType;
typedef int Status;
#define MAX_TREE_SIZE 100

typedef struct PTNode {
	TElemType data;
	int parent;
}PTNode;
typedef struct {
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;
}PTree;
//创建树
void CreateTree(PTree *P) {
	P->nodes[0].parent = -1;
	char a;
	printf("请输入根节点：");
	scanf("%c", &(P->nodes[0].data));
	printf("请输入根节点的结点个数：");
	scanf("%d", &(P->n));
	for (int i = 1; i < P->n; i++) {
		printf("请输入结点的数据：");
		scanf("%c", &(P->nodes[i].data));
		printf("请输入此结点的父节点:");
		scanf("%c", &a);
		for (int j = 0; j < i; j++) {
			if (a == P->nodes[j].data) {
				P->nodes[i].parent = j;
				break;
			}
		}
	}
	return 0;
}
//计算树的深度
int  DepthTree(PTree P) {
	int a, par;
	int depth = 0;
	for (int i = 0; i < P.n; i++) {
		a = 1;
		par = P.nodes[i].parent;
		while (par != -1) {
			par = P.nodes[par].parent;
			a++;
		}
	}
	if (depth < a) {
		depth = a;
	}
	return depth;
}