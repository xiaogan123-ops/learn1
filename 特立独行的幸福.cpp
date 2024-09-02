#include<stdio.h>
int main(void){
	int n;
	int max=0;
	int c[5]={0,0,2,0,2};
	for(int i=0;i<5;i++){
		if(max>c[i]) max=max;
		else max=c[i];
	}
	for(int i=4;i>=0;i++){
		if(max>1) {
			if(max==c[i]) n=i;
		}
		else printf("%d",0);
	}
	printf("%d",n);
	return 0;
}
