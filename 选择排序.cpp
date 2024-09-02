#include<stdio.h>
void swap(int a[],int n){
	int i,j,t;
	for(i=0;i<n-1;i++){
		t=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[t]){
				t=j;
			}
		}
		int temp=a[i];
		a[i]=a[t];
		a[t]=temp;
	}
}
int main(void){
	int i,n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	swap(a,n);
	for(i=0;i<n;i++){
		if(i==n-1){
			printf("%d",a[i]);
		}else 
		printf("%d ",a[i]);
	}
	return 0;
}
