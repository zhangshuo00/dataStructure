//#include<stdio.h>
////
////
////typedef struct{
////	int i,j;
////	ElemType e;
////}Triple;
////typedef struct{
////	Triple data[MAXSIZE+1];
////	int mu,nu,tu;
////}TSMatrix;
////
//////TSMatrix NewMatrix(int m,int n){
//////	TSMatrix M;
//////	M.mu = m;
//////	M.nu = n;
//////	M.tu = 0;
//////	return M;
//////}
////Status CreateSMatrix(TSMatrix *M){
////	int i,m,n;
////	ElemType e;
////	int k;
////	printf("��������������������������Ԫ������\n");
////	scanf("%d,%d,%d", &(*M).mu, &(*M).nu, &(*M).tu);
////	(*M).data[0].i = 0;
////	for(i =1;i<=(*M).tu;i++){
////		do{
////			printf("�밴��������� %d ������Ԫ���У�1~%d��,""�У�1~%d��,Ԫ��ֵ��\n",i,(*M).mu,(*M).nu);
////			scanf("%d,%d,%d",&m,&n,&e);
////			k=0;
////			if(m<1 || m>(*M).mu || n<1 || n>(*M).nu)
////				k=1;
////			if(m<(*M).data[i-1].i || m == (*M).data[i-1].i && n <= (*M).data[i-1].j)
////				k=1;
////		}while(k);
////		(*M).data[i].i = m;
////		(*M).data[i].j = n;
////		(*M).data[i].e = e;
////	}
////	return 1;
////}
//////����ϡ�����M
////void DestroySMatrix(TSMatrix *M){
////	(*M).mu = 0;
////	(*M).nu = 0;
////	(*M).tu = 0;
////}
//////���ϡ�����M
////void PrintSMatrix(TSMatrix M){
////	int i;
////	printf("\n %d �У�%d �У�%d ������Ԫ \n",M.mu,M.nu,M.tu);
////	printf("---------------------\n");
////	printf("%4s %4s %8s\n","i","j","e");
////	printf("---------------------\n");
////	for(i =1;i<=M.tu;i++){
////		printf("%4d %4d %8d\n",M.data[i].i,M.data[i].j,M.data[i].e);
////	}
////	printf("---------------------");
////}
//////
////������:6-1
////����:��˷
////�༶:8��
////ѧ��:2017012067
////����:2018-11-11
//
//#define MAXSIZE 12500
//#define OK 1
//#define ERROR 0
//typedef float ElemType;
//typedef int Status;
//
//Status JudgingNonZero(TSMatrix M,int a,int b){
//	for(int x =1;x<M.mu;x++){
//		if(a == M.data[x].i && b == M.data[x].j){
//			return M.data[x].e;
//		}else{
//			return ERROR;
//		}
//	}
//}
//
//#define MAXSIZE 100
//#define MAXROW 20
//typedef struct
//{
//	int j;//����Ԫ�����±�
//	int e;//����Ԫ��ֵ
//}Second;
//typedef struct
//{
//	Second data[MAXSIZE+1];
//	int rpos[MAXROW+1];
//	int mu,nu,tu;
//}TSMatrix;
//
////������:6-2
////����:��˷
////�༶:8��
////ѧ��:2017012067
////����:2018-11-11
//int judge(TSMatrix A,int m,int n)
//{
//	int i,j;
//	if(m<0 || m>A.mu || n<0 || n>A.nu)
//		return 0;
//	i = A.rpos[m];
//	if(m == A.mu)
//		j = A.tu;
//	else
//		j = A.rpos[m+1]-1;
//	for(int k = i;k<=j;k++){
//		if(A.data[k].j = j)
//			int e = A.data[k].e;
//	}
//	return 1;
//}
////�ŵ��ǿ��������ȡϡ���������һ�еķ���Ԫ������Ԫ��˳���ֻ�ܰ���˳���ȡ
//
////������:6-3
////����:��˷
////�༶:8��
////ѧ��:2017012067
////����:2018-11-11
//
////��1������A����� = 6*8*6 = 288
////��2��1000+��6*8-1��*6=1282
////��3��1000+��1*8+4��*6 = 1072
////��4��1000+��6*7+4��*6 = 1276
//int main(void)
//{
//	TSMatrix A;
//	int Aa,Ab,Ac,i,mm,nn,result;
//	int Aelemj,Aeleme;
//	int Anum=1;
//	int k,sum=0;
//	printf("���������A������������������Ԫ����:");
//	scanf("%d%d%d",&Aa,&Ab,&Ac);
//	A.mu=Aa;
//	A.nu=Ab;
//	A.tu=Ac;
//	printf("���������A�ķ���Ԫ��");
//	for(i=1;i<=A.tu;i++)
//	{
//		scanf("%d%d",&Aelemj,&Aeleme);
//		A.data[i].j=Aelemj;
//		A.data[i].e=Aeleme;
//	}
//	printf("���������A������ʼ���������飩��");
//	for(k=1;k<=A.mu;++k)
//	{
//		scanf("%d",&sum);
//		A.rpos[k]=sum;
//	}
//	printf("���������Ԫ�ص��±�ֵa,b:");
//	scanf("%d",&mm);
//	scanf("%d",&nn);
//	result=judge(A,mm,nn);
//    printf("���������Ԫ��%d\n",result);
//	return 0;
//}
#include <stdio.h>

int candp(int a,int b,int c){ 
	int r=1;
	b=b+1;
	while(b!=1){
		r = r*a;
		r=r%c;
		b--;
	}
	printf("%d\n",r);
	return r;
}
void main(){
	int p,q,e,d,m,n,t,c,r;
	char s;
	printf("please input the p,q: ");
	scanf("%d %d",&p,&q);
	n=p*q;
	printf("the n is %3d\n",n);
	t=(p-1)*(q-1);
	printf("the t is %3d\n",t);
	printf("please input the e: ");
	scanf("%d",&e);
	if(e<1||e>t){
		printf("e is error,please input again: ");
		scanf("%d",&e);
	}
	d=1;
	while(((e*d)%t)!=1)d++;
	printf("then caculate out that the d is %d\n",d);
	printf("the cipher please input 1\n");
	printf("the plain please input 2\n");
	scanf("%d",&r);
	switch(r){
		case 1: printf("input the m: "); /*����Ҫ���ܵ���������*/
			scanf("%d",&m);
			c=candp(m,e,n);
			printf("the cipher is %d\n",c);break;
		case 2: printf("input the c: "); /*����Ҫ���ܵ���������*/
			scanf("%d",&c);
			m=candp(c,d,n);
			printf("the cipher is %d\n",m);break;
}
getchar();
}