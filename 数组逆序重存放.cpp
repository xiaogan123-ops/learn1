#include<stdio.h>
int main(void){
	int a[100],b[100];
	int n,t;
	scanf("%d",&n);
	t=n-1;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[t]=a[i];
		t--;
	}
	for(int i=0;i<n;i++){
		printf("%d ",b[i]);
	}
	return 0;
}
