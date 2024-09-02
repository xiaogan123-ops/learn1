#include<stdio.h>
int main(void){
	int n;
	double t;
	scanf("%d",&n);
	if(n<=0){
		printf("Invalid Vakue");
	}else if(n<=50){
		t=n*0.53;
		printf("%lf",t);
	}else {
		t=50*0.53+(n-50)*0.58;
		printf("%lf",t);
	}
	return 0;
}
