#include<stdio.h>
int main(void){
	int a,b,c,d,e;
	scanf("%d %d",&a,&b);
	c=a/100*60+a%100+b;
	d=c/60;
	e=c%60;
	if(d>0){
		printf("%d",d*100+e);
	}else printf("0%d",e);
	return 0;
}
