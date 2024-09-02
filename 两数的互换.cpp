#include<stdio.h>
void swap(int *x,int *y){
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
int main(void){
	int x,y;
	scanf("%d %d",&x,&y);
	swap(&x,&y);
	printf("After swap:%d,%d",x,y);
	return 0;
}
