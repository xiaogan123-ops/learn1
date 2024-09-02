#include<stdio.h>
double face(int m);
int main(void){
	int n,m;
	double total=0,sum=0,other=0,aver=0;
	scanf("%d %d",&n,&m);
	total=face(m);
	sum=face(n);
	other=face(m-n);
	aver=total/(sum*other);
	printf("result = %.0lf",aver);
	return 0;
}
double face(int m){
	double a=1;
	for(int i=1;i<=m;i++){
		a*=i;
	}
	return a;
}

