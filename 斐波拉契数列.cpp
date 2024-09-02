#include<stdio.h>
int main(void){
	int i,n;
	int a[46]={1,1};
	scanf("%d",&n);
	for(i=2;i<n;i++){
		a[i]=a[i-1]+a[i-2];
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
		if((i+1)%5==0){
			printf("\n");
		}
	}
	return 0;
}
