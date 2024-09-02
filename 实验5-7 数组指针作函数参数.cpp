#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i,m,n,total;
	int a[31];
	float b[31];
	int *p;
	scanf("%d %d\n",&m,&n);
	if((p=(int*)calloc(n,sizeof(int)))==NULL){
		exit(1);
	}
	for(i=0;i<m;i++){
		for(int j=0;j<n;j++){
		scanf("%d",p+j);
		}
		total=0;
		for(int j=0;j<n;j++){
			total=total+*(p+j);
		}
		a[i]=total;
		b[i]=total*1.0/n;
	}
	for(i=0;i<m;i++){
		printf("%d %.1f\n",a[i],b[i]);
	}
	free(p);
	return 0;
}
