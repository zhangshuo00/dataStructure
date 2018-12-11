//#include<stdio.h>
//#define LIST_INITSIZE 100
//#define ElemType int
//#define Status int
//#define OK 1
//#define ERROR 0
//
//typedef struct{
//	ElemType elem[LIST_INITSIZE];
//	int length;
//}SqList;
////链表初始化 
//int InitList(SqList *L){
//	int i;
//	for(i=0;i<LIST_INITSIZE;i++){
//		L->elem[i]=NULL; 
//	}
//	L->length=0;
//	return OK;
//}
////插入 
//int ListInsert(SqList *L,int i,ElemType elem){
//	if(L->length==0||L->length>=LIST_INITSIZE||i<0||i>=L->length)
//		return ERROR;
//	L->length++;
//	int j=0;
//	for(j=L->length;j>i;j--){
//		L->elem[j]=L->elem[j-1];
//	}
//	L->elem[i]=e;
//	return OK;
//}
////打印 
//void ListPrint(SqList *L){
//	int i;
//	for(i=0;i<L->length;i++){
//		printf("%d\t",L->elem[i]);
//	}
//	printf("\n");
//}
////删除 
//int ListDelete(SqList *L,int i,ElemType *e){
//	if(i>L->length||i<0||L->length==0)return ERROR;
//	int j;
//	for(j=i;j<L->length;j++){
//		L->elem[j]=L->elem[j+1];
//	}
//	L->length--;
//	return OK;
//}
////拆分
//void DisCreat(SqList *L,SqList *B,SqList *C){
//	int i;
//	int j=0,k=0;
//	for(i=0;i<L->length;i++){
//		if(L->elem[i]<0){
//			B->elem[j]=L->elem[i];
//			B->length++;
//			j++;
//		}
//		else{
//			C->elem[k]=L->elem[i];
//			C->length++;
//			k++;
//		}
//	}	
//} 
////
//int main(void)
//{
//	SqList L;
//	SqList B,C;
//	int i;
//	ElemType e;
//	ElemType data[9]={11,-22,33,-3,-88,21,77,0,-9};
//	InitList(&L);
//	InitList(&B);
//	InitList(&C);
//	for(i=1;i<=9;i++){
//		ListInsert(&L,i,data[i-1]);
//	}
//	printf("插入完成后L=:");
//	ListPrint(&L);
//	
//	ListDelete(&L,1,&e);
//	printf("删除第一个后L=:");
//	ListPrint(&L);
//	
//	DisCreat(&L,&B,&C);
//	printf("拆分L后B=:");
//	ListPrint(&B);
//	printf("拆分L后C=:");
//	ListPrint(&C);
//	printf("拆分L后L=:");
//	ListPrint(&L);
//	
//	return 0;
//}
#include <iostream.h>
#define MAXSIZE 50
typedef int ElemType;
typedef struct
{
	ElemType list[MAXSIZE];
	int size;
}List;
void initList(List *L);
int listSize(List L);
int listEmpty(List *L);
ElemType getElement(List L,int pos);
void traverseList(L);
int find(List L,ElemType *item);
int update(List *L,ElemType *item);
void insertRear(List *L,ElemType item);
void insertFront(List *L,ElemType item);
void insert(List *L,ElemType item);
ElemType deleteFront(List *L);
int deleteL(List *L,ElemType *item);
void sort(List *L);
void main()
{
	List L1;
	int i;
	ElemType d;
	initList(&L1);
	for(i=0;i<10;i++)
	{
		insertRear(&L1,i);
	}
	traverseList(L1);
	printf("/n");
	printf("the List's size is %d ./n",listSize(L1));
	printf("the fourth element in the list is %d./n",getElement(L1,4));
	if(1==find(L1,11))
	{
		printf("this element 11 is included the list./n");
	}
	else
	{
		printf("no such element in the list./n");
	}
	insertFront(&L1,11);
	traverseList(L1);
	printf("/n");
	sort(&L1);
	//printf("to delete the first element %d./n",deleteFront(&L1));
	traverseList(L1);
	printf("/n");
	insert(&L1,5);
	traverseList(L1);
	printf("/n");
	printf("to delete element 5 from the list./n");
	d=5;
	deleteL(&L1,&d);
	traverseList(L1);
	printf("/n");


}
void initList(List *L)
{
	L->size=0;
}
int listSize(List L)
{
	return L.size;
}
int listEmpty(List *L)
{
	if(0==L->size)
	{
		return 1;
	}
	return 0;
}
ElemType getElement(List L,int pos)
{
	if(pos<1 || pos>L.size)
	{
		printf("pos is out range!/n");
		exit(1);
	}
	return L.list[pos-1];
}
void traverseList(List L)
{
	int i;
	for(i=0;i<L.size;i++)
	{
		printf("%d ",L.list[i]);
	}
}

int find(List L,ElemType *item)
{
?int i;
?for(i=0;i<L.size;i++)
?{
??if(item==L.list[i])
??{
???*item=L.list[i];
???return 1;
??}
?}
?return 0;
}

int update(List *L,ElemType *item)
{
?int i;
?for(i=0;i<L->size;i++)
?{
??if(item==L->list[i])
??{
???L->list[i]=item;
???return 1;
??}
?}
?return 0;
}

void insertRear(List *L,ElemType item)
{
?if(L->size==MAXSIZE)
?{
??printf("L->list overflow!!/n");
??exit(1);
?}
?L->list[L->size]=item;
?L->size++;
}

void insertFront(List *L,ElemType item)
{
?int i;
?if(L->size==MAXSIZE)
?{
??printf("L->list overflow!!/n");
??exit(1);
?}
?for(i=L->size-1;i>=0;i--)
?{
??L->list[i+1]=L->list[i];
?}
?L->list[0]=item;
?L->size++;
}

void insert(List *L,ElemType item)
{
	int i,j;
	if(L->size==MAXSIZE)
	{
		printf("L->list overflow!!/n");
		exit(1);
	}
	for(i=0;i<L->size;i++)
	{
		if(item<L->list[i])
		{
			break;
		}
	}
	for(j=L->size-1;j>=i;j--)
	{
		L->list[j+1]=L->list[j];
	}
	L->list[i]=item;
	L->size++;
}

ElemType deleteFront(List *L)
{
?ElemType temp;
?int i;
?if(1==listEmpty(L))
?{
??printf("L->list overflow!!/n");
??exit(1);
?}
?
?temp=L->list[0];
?for(i=1;i<L->size;i++)
?{
??L->list[i-1]=L->list[i];
?}
?L->size--;
?return temp;
}

int deleteL(List *L,ElemType *item)
{
?int i,j;
?if(1==listEmpty(L))
?{
??printf("L->list no any element!!/n");
??exit(1);
?}
?for(i=0;i<L->size;i++)
?{
??if(*item==L->list[i])
???break;
?}
?if(i==L->size)
?{
??printf("L->list no such element!!/n");
??return 0;
?}
?*item=L->list[i];
?for(j=i+1;j<L->size;j++)
?{
??L->list[j-1]=L->list[j];
?}
?L->size--;
?return 1;

}

void sort(List *L)
{
?int i,j;
?ElemType x;
?for(i=1;i<L->size;i++)
?{
??x=L->list[i];
??for(j=i-1;j>=0;j--)
??{
???if(x<L->list[j])
???{
????L->list[j+1]=L->list[j];
???}
???else
???{
????break;
???}
??}
??L->list[j+1]=x;
 }
}

