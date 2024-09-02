#include<stdio.h>
int MAX(int x,int y){
	if(x>y)
		return x;
	else return y;
}
int main(void)
{
	int max, total,count=0,a[6];
	for(int i=0;i<6;i++){
		scanf("%d",&a[i]);
	}
     max=MAX(MAX(MAX(a[0],a[1]),a[2]),a[3]);
	for(int i=0;i<4;i++){
		if(max-a[i]>a[5]||max<a[4]){
			count++;
			if(count==1)
			total=i+1;
		}
	}
	if(count==0){
		printf("Normal\n");
	}else if(count==1){
		printf("Warning: please check #%d!\n",total);
	}else
		printf("Warning: please check all the tires!\n");
	return 0;
}
