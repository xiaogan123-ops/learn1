#include<stdio.h>
int main(void){
	int blank=0,digit=0,other=0;
	char a[10000];
	for(int i=0;i<10000;i++){
		a[i]=getchar();
		if(a[i]=='\n') 
			break;
	}
	for(int i=0;a[i]!='\n';i++){
		if(a[i]==' ') blank++;
		else if(a[i]>='0'&&a[i]<='9')  digit++;
		else other++;
	}
	printf("blank = %d, digit = %d, other = %d",blank,digit,other);
	return 0;
}
