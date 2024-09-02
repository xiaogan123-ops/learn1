#include<stdio.h>
int main(void){
	int a;
	char b;
	double c,d;
	scanf("%lf %d %c %lf",&c,&a,&b,&d);
	printf("%c %d %.2lf %.2lf",b,a,c,d);
	return 0;
}
