#include<stdio.h>
int main(void){
	int a,b,c,i,n,t,max=0;
	int sum[10001];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d-%d %d",&a,&b,&c);
		sum[a]+=c;
		if(sum[a]>sum[max]){
			t=a;
			sum[max]=sum[a];
		}
	}
	printf("%d %d",t,sum[max]);
	return 0;
}
