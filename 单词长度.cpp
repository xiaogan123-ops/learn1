#include<stdio.h>
#include<string.h>
int main(void) {
	int len,i=0,j=0,sum=0,t=0;
	char a[1001];
	while((a[i]=getchar())!='\n'){
		i++;
	}
	len = i;
	a[len] = ' ';
	for ( i = 0; i <= len; i++) {
		if (a[i] != ' ') {
			sum++;
		}else {
			if(sum==0){
				sum=0;
			}else {
				if(i!=len){
		  printf("%d,",sum);
				}else 
					printf("%d",sum);
		sum = 0;
				}
	}
	}
 
}
