#include<stdio.h>
int main(void){
	int i,n,m,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			printf("%d ",m);
			m--;
		}
		printf("\n");
	}
	return 0;
}
