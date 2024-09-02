#include<stdio.h>
int main(void){
	int i,j,n,t;
	while(scanf("%d",&n)!=EOF){
		int a[n][n];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<i;j++){
			t=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=t;
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d",a[i][j]);
				if(j!=n-1) printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
