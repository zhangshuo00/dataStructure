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
Status CreateBiTree(BiTree &T){
	TElemType ch;
	TElemType temp;
	scanf("%d",&ch);
	temp == getchar();
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
	int depth = 0;
	CreateBiTree(root);
}

