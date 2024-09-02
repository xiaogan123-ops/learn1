#include<stdio.h>
int main(void){
	int n,numble,i,t=0;
	scanf("%d %d",&n,&numble);
	if(numble%2==0){
		t=0;
	}else t=1;
	for(i=1;i<=numble;i++){
		if(i==1){
			n=n;
		}else {
			if(i%2==0){
			n=n+n;
		}else n=n;
		}
	}
	printf("%d %d",t,n);
	return 0;
}
