#include<stdio.h>
#include<math.h>
int main(void){
	int i,j,t,other,sum,n,m;
	scanf("%d %d",&n,&m);
	if(n>m||n>500){
		return 0;
	}else {
		for(i=n;i<=m;i++){
			if(i<=1){
				t=0;
			}else if(i==2){
				t=1;
			}else {
				t=1;
				other=sqrt(i);
					for(j=2;j<=other;j++){
						if(i%j==0){
							t=0;
							break;
						}
					}
			}
			if(t==1){
				printf("%d ",i);
				sum++;
				if(sum%10==0){
					printf("\n");
				}
			}
		}
	}
    return 0;
}
