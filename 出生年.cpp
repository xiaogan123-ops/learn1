#include<stdio.h>
int numble(int y);
int main(void){
	int y,n,total=0;
	scanf("%d %d",&y,&n);
	while(numble(y)!=n){
		y++;
		total++;
	}
	printf("%d %04d",total,y);
	return 0;
}
int numble(int y){
	int sum=0;
	int a[10]={0};
	a[y%10]=1;
	a[y/10%10]=1;
	a[y/100%10]=1;
	a[y/1000]=1;
	for(int i=0;i<10;i++){
		if(a[i]==1){
			sum++;
		}
	}
	return sum;
}
