//������:5_3
//����:��˷
//�༶:8��
//ѧ��:2017012067
//����:2018-11-03

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int Status;
#define OVERFLOW -2
#define ERROR 0
#define OK 1

typedef struct{
	char *ch;
	int length;
}HString;

//����һ����ֵ���ڴ�����chars�Ĵ�T
Status StrAssign(HString&T,char *chars){
	if(T.ch)
		free(T.ch);
	int i = strlen(chars);
	if(!i){
		T.ch = NULL;
		T.length = 0;
	}else{
		T.ch = (char*)malloc(i*sizeof(char));
		if(!T.ch)
			exit(OVERFLOW);
		for(int j = 0;j<i;j++)
			T.ch[j] = chars[j];
		T.length = i;
	}
	return OK;

}

//����S��Ԫ�ظ�������Ϊ���ĳ���
int StrLength(HString S){
	return S.length;
}
//��S>T,�򷵻�ֵ>0;��S=T�򷵻�ֵ=0����S<T���򷵻�ֵ<0
int StrCompare(HString S,HString T){
	for(int i=0;i<S.length && i<T.length;i++){
		if(S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}
//��S��Ϊ�մ�
Status ClearString(HString &S){
	if(S.ch){
		free(S.ch);
		S.ch = NULL;
	}
	S.length = 0;
	return OK;
}
//��T������S1��S2���Ӷ��ɵ��´�
Status Concat(HString &T,HString S1,HString S2){
	T.length = S1.length + S2.length;
	if(T.ch)
		free(T.ch);
	T.ch = (char*)malloc(T.length *sizeof(char));
	if(!T.ch)
		exit(OVERFLOW);
	for(int i=0;i<S1.length;i++)
		T.ch[i] = S1.ch[i];
	for(int i=0;i<S2.length;i++)
		T.ch[S1.length+i] = S2.ch[i];
	return OK;
}
//��Sub���ش�S�ĵ�posλ����ĳ���len���Ӵ�
Status SubString(HString &Sub,HString S,int pos,int len){
	if(pos<1 || pos>S.length || len<0 ||len>S.length-pos+1)
		return ERROR;
	if(Sub.ch)
		free(Sub.ch);
	if(!len){
		Sub.ch = NULL;
		Sub.length =0;
	}else{
		Sub.ch = (char*)malloc(len*sizeof(char));
		if(!Sub.ch)
			exit(OVERFLOW);
		for(int i=0;i<len-1;i++)
			Sub.ch[i] = S.ch[pos-1+i];
		Sub.length = len;
	}
	return OK;
}
//����T���뵽��S�ĵ�pos���ַ�֮ǰ
Status StrInsert(HString *S,int pos,HString T){
	if(pos<1 || pos>S->length+1)
		return ERROR;
	if(T.length){
		S->ch = (char*)realloc(S->ch,(S->length + T.length)*sizeof(char));
		if(!S->ch)
			exit(OVERFLOW);
		for(int i=S->length-1;i>=pos-1;--i)
			S->ch[i+T.length] = S->ch[i];
		for(int i=0;i<T.length;i++)
			S->ch[pos-1+i] = T.ch[i];
		S->length += T.length;
	}
	return OK;
}

int main(void){
	
}