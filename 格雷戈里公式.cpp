#include<stdio.h>
#include<math.h>
int main(void){
	int i,other,t=-1;
	double eps,total=0,sum,flog;
	scanf("%lf",&eps);
	for(i=0;;i++){
		t=-t;
		other=2*i+1;
		flog=t*1.0/other;
		total+=flog;
		if(fabs(flog)<eps){
			break;
		}
	}
	sum=total*4;
	printf("%lf\n",sum);
	printf("%d",i);
	return 0;
}
