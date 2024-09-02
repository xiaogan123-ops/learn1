#include<stdio.h>
int main(void){
	int n;
	int a[100];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		if(a[i]>a[i+1]){
			int t;
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}else a[i+1]=a[i+1];
	}
	printf("%d",a[4]);
	return 0;
}
