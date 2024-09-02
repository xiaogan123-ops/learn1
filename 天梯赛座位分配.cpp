#include<stdio.h>
#include<stdio.h>
#define Max_a 101
#define Max_b 11
#define Max_c 11
int main(void){
	int a[Max_a][Max_b][Max_c];
	int p;
	int i,j,k,n,x,max;
	scanf("%d",&n);
	int b[n];
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n;i++){
		if(max<b[i]){
			max=b[i];
		}
	}
	for(i=1;i<=max;i++){
		for(j=1;j<=10;j++){
			for(k=1;k<=n;k++){
				if(i<=b[k]){
					if(p==k){
						x+=2;
					}else x++;
					a[k][i][j]=x;
					p=k;
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		printf("#%d\n",i);
		for(k=1;k<=b[i];k++){
			for(j=1;j<=10;j++){
				printf("%d",a[i][k][j]);
				if(j%10!=0){
					printf(" ");
				}else printf("\n");
			}
		}
	}
}
