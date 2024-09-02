#include<stdio.h>
int main(void){
	char a[2];
	getchar();
	for(int i=0;i<2;i++){
		scanf("%s",&a[i]);
	}
	for(int i=0;i<2;i++){
		printf("%s ",a);
	}
	return 0 ;
}
