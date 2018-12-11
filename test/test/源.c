#include<stdio.h>
int main(void){
	int i,j,a,b,max,min,sum;
	int maxgongyue,mingongbei;
	scanf("%d %d",&a,&b);

	if(a>b){
		max=a;
		min =b;
	}else{
		max=b;
		min =a;
	}

	for(i=min;;i--){
		if(max%i==0)
			maxgongyue = i;
		break;
	}

	for(j=max;;j--){
		if(j%min==0)
			mingongbei =j;
		break;
	}
	sum = maxgongyue *mingongbei;
	printf("%d",sum);

	
}