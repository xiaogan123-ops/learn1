#include<stdio.h>
int main(void){
	char *a[5];
	for(int i=0;i<5;i++){
		scanf("%s",a[i]);
	}
	printf("%s",a+1);
	return 0;
}
