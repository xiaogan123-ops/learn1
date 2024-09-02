#include<stdio.h>
#include<math.h>
int face(int n);
int main(void){
	int n,total=0;
	scanf("%d",&n);
	total=face(n);
	printf("result = %d",total);
	return 0;
}
int face(int n){
	if(n==1){
		return 2;
	}else return pow(2,n)+face(n-1);
}
