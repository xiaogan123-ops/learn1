#include<stdio.h>
int main(void){
	int a[4],i;
	int sum=0;
	double average=0;
	for(i=0;i<4;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	average=(sum*1.0)/4;
	printf("Sum = %d; Average = %.1lf",sum,average);
	return 0;
}
