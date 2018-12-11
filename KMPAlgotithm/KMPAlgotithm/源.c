#include<stdio.h>
#include<stdlib.h>

void makeNext(char *str,int *next,int len){
	next[0] = -1;
	int k = -1;
	for(int q = 1;q<=len-1;q++){
		while(k>-1 && str[k+1] != str[q]){
			k = next[k];
		}
		if(str[k+1 == str[q]]){
			k+=1;
		}
		next[q] = k;
	}

}
int main(void){
	
}