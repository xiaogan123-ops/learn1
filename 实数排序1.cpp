#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i,n,j;
	double t;
	scanf("%d",&n);
	double *pr=(double *)malloc(sizeof(double)*n);
	for(i=0;i<n;i++){
		scanf("%lf",pr+i);
	}
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(*(pr+j)<*(pr+j+1)){
				t=*(pr+j);
				*(pr+j)=*(pr+j+1);
				*(pr+j+1)=t;
			}
		}
	}
	for(i=0;i<n;i++){
			printf("%.2lf",*(pr+i));
		if(i!=n-1){
			printf(" ");
		}
	}
	return 0;
}
