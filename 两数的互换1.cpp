#include<stdio.h>
int main(void){
	int t,*pr,*p;
	int a,b;
	scanf("%d %d",&a,&b);
	pr=&a;
	p=&b;
	t=*pr;
	*pr=*p;
	*p=t;
	printf("After swap:%d,%d",*pr,*p);
	return 0;
	
}
