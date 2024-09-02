#include<stdio.h>
int main(void){
	int n,a;
	int  total=0,sum=0,other=0,num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(a>=0&&a<=18){
			total++;
		}else if(a>18&&a<=35){
			sum++;
		}else if(a>35&&a<=60){
			other++;
		}else num++;
	}
	printf("%.2lf%\n",total*1.0/n*100);
	printf("%.2lf%\n",sum*1.0/n*100);
	printf("%.2lf%\n",other*1.0/n*100);
	printf("%.2lf%\n",num*1.0/n*100);
	return 0;
}
