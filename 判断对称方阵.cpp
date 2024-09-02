#include<stdio.h>
int main(void){
	int i,j,n,t,flag=1;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		int a[n][n];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<i;j++){
				if(a[i][j]!=a[j][i]){
					flag=0;
					break;
				}
			}
		}
		if(flag==1){
			printf("Yes\n");
		}else printf("No\n");
	}
	return 0;
}
