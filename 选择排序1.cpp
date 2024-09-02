#include<stdio.h>
int main(void){
	int i,j,n,t,mix;
	scanf("%d",&n);
	int a[100];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		mix=i;
		for(j=i+1;j<n;j++){
			if(a[mix]>a[j]){
				mix=j;
			}
		}
		t=a[mix];
		a[mix]=a[i];
		a[i]=t;
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
