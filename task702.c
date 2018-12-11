#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef char TElemType ;
typedef int Status;

//�ṹ��
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//�������������ʾ�Ķ�����
Status CreateBiTree(BiTree *T){
	TElemType ch;
	scanf("%c",&ch);
	if(ch == -1){
		T = NULL;
	}else{
		T = (BiTree*)malloc(sizeof(BiTNode));
		T.data = ch;
		printf("����%d�����ӽ�㣺",ch);
		T.lchild = CreateBiTree(T.lchild);
		printf("����%d�����ӽ�㣺",ch);
		T.rchild = CreateBiTree(T.rchild);
	}
	return T;
}
//��������������
Status BT_Depth(BiTree T){
	int ldepth = 0;
	int rdepth = 0;
	if(T == NULL)
		return -1;
	if(T->lchild!=NULL)
		ldepth = BT_Depth(T->lchild);
	else
		ldepth = -1;
	if(T->rchild != NULL)
		rdepth = BT_Depth(T->rchild);
	else
		rdepth = -1;
	if(ldepth>rdepth)
		return ldepth;
	else
		return rdepth;
}
//
int main(void){
	BiTNode *root = NULL;
	BiTree *tree;
	int depth = 0;
	CreateBiTree(tree);
}

