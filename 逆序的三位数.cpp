#include<stdio.h>
int main(void){
	int a,t,b,total,sum,num,c;
	scanf("%d",&a);
	t=a%10;
	b=a%100;
	if(t==0&&b!=0){
		total=a/10;
		sum=total%10;
		num=total/10;
		printf("%d%d",sum,num);
		return 0;
	}
	if(t==0&&b==0){
		total=a/100;
		printf("%d",total);
		return 0;
	}
	total=a%10;
	sum=a/10;
	num=sum%10;
	c=sum/10;
	printf("%d%d%d",total,num,c);
	return 0;
}
