#include<stdio.h>
int mian(void){
	int i,t,sum,total=0;
	int a[101];
	for(i=0;;i++){
		scanf("%d ",&a[i]);
		total++;
		if(a[i]<0)
			break;
	}
	t=total-1;
	if(t>=3){
		for(i=1;i<t;i++){
			for(int j=0;j<t-i;j++){
				if(a[j]<a[j+1]){
					sum=a[j];
					a[j]=a[j+1];
					a[j+1]=sum;
				}
			}
		}
		printf("%d %d %d",a[0],a[1],a[3]);
	}else if(t==2){
		if(a[0]<a[1]){
			sum=a[0];
			a[0]=a[1];
			a[1]=sum;
		}
		printf("%d %d #",a[0],a[1]);
	}else if(t==1){
		printf("%d # #",a[0]);
	}
	return 0;
}
