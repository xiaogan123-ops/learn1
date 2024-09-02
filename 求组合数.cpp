#include<stdio.h>
int main(void){
	int i,n,m,sum=1,total=1,other=1;
	double  aver=0;
	scanf("%d %d",&n,&m);
	for(i=m;i>=1;i--){
		sum*=i;
	}
	for(i=n;i>=1;i--){
		total*=i;
	}
	for(i=m-n;i>=1;i--){
		other*=i;
	}
	aver=(sum)/(total*other);
	printf("result = %.0lf",aver);
	return 0;
}
