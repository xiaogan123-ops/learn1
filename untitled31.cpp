#include<stdio.h>
int main(void){
	int i,a,b,other,t=0,total=0;
	int c[7];
	for(i=0;i<7;i++){
		scanf("%d %d",&a,&b);
		if(i==0)  total=a+b;
		c[i]=a+b;
		if(c[i]>8) other++;
	}
	if(other==0){
		printf("%d",0);
	}else for(i=0;i<7;i++){
		if(total<c[i]){
			t=i+1;
			total=c[i];
		}
	}
	printf("%d",t);
	return 0;
}
