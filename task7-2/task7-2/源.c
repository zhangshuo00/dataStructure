//������:7-2
//����:��˷
//�༶:8��
//ѧ��:2017012067
//����:2018-11-24
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int TElemType ;
typedef int Status;

//�ṹ��
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//�������������ʾ�Ķ�����
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
		printf("����%d�����ӽ�㣺",ch);
		CreateBiTree(T->lchild);
		printf("����%d�����ӽ�㣺",ch);
		CreateBiTree(T->rchild);
	}
	return 1;
}
//��������������
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

//������:7-3
//����:��˷
//�༶:8��
//ѧ��:2017012067
//����:2018-11-24
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
//������
void CreateTree(PTree *P) {
	P->nodes[0].parent = -1;
	char a;
	printf("��������ڵ㣺");
	scanf("%c", &(P->nodes[0].data));
	printf("��������ڵ�Ľ�������");
	scanf("%d", &(P->n));
	for (int i = 1; i < P->n; i++) {
		printf("������������ݣ�");
		scanf("%c", &(P->nodes[i].data));
		printf("������˽��ĸ��ڵ�:");
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
//�����������
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