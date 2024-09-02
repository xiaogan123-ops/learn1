#include<stdio.h>
int main(void){
	int str[24] ,a[10000];
	for(int i=0;i<24;i++){
		scanf("%d",&str[i]);
	}
	int b,i=0;
	do{
		scanf("%d",&b);
		a[i]=str[b];
		i++;
	}while(b>=0&&b<=23);
	for(int j=0;j<i-1;j++){
		if(a[j]>50){
			printf("%d Yes\n",a[j]);
		}else{
			printf("%d No\n",a[j]);
		}
	}	
	return 0;
}
