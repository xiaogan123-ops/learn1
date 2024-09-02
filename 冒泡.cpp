#include<stdio.h>
void bubbleSort(int *p,int c);
int main(void){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bubbleSort(a,n);
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
void bubbleSort(int *p,int c){
	int i,j,t;
	for(i=1;i<c;i++){
		for(j=0;j<c-i;j++){
			if(*(p+j)>*(p+j+1)){
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t;
			}
		}
	}
}
