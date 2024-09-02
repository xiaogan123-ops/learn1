#include<stdio.h>
#include<math.h>
int a[10001];
int n,m;
int sushu(int x){
	if(x==1){
		return 0;
	}
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
int pingfang(int x){
	int total,a,b,c,d;
	if(x==10000){
		return 1;
	}
	a=x/1000;
	b=x/100%10;
	c=x%100/10;
	d=x%10;
	total=a*a+b*b+c*c+d*d;
	return total;
}
int xingfu(int x){
	int b[10001];
	int i,j;
	for(i=0;a[x]!=1;i++){
		b[i]=a[x];
		x=a[x];
		for(j=0;j<i;j++){
			if(b[j]==b[i]){
				return 0;
			}
		}
	}
	return 1;
}
int duli(int x){
	int i;
	for(i=n;i<=m;i++){
		if(a[i]==x){
			return 0;
		}
	}
	return 1;
}
int main(void){
	int flog=1,i,count,x;
	scanf("%d %d",&n,&m);
	for(i=1;i<10000;i++){
		a[i]=pingfang(i);
	}
	for(i=n;i<=m;i++){
		if(xingfu(i)&&duli(i)){
			printf("%d ",i);
			count=1;
			x=i;
			while(pingfang(x)!=1){
				count++;
				x=pingfang(x);
			}
			if(sushu(i)==1){
				count*=2;
				
			}
			printf("%d",count);
			flog=0;
			printf("\n");
		}
	}
	if(flog){
		printf("SAD");
	}
	return 0;
}
