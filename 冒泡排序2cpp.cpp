#include<stdio.h>
void bubbleSort(int *p,int c){
	int i,j;
	int t;
	for(i=1;i<c;i++){
		for(j=0;j<c;j++){
			if(*(p+j)>*(p+j+1)){
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t;
			}
		}
	}
}
int main(void){
	int i,c;
	scanf("%d",&c);
	int a[c+1];
	for(i=0;i<c;i++){
		scanf("%d",&a[i]);
	}
	bubbleSort(a,c);
	for(i=0;i<c;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
