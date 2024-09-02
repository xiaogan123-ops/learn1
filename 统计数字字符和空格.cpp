#include<stdio.h>
int main(void){
	int ch,a=0,b=0,c=0;
	getchar();
	while((ch=getchar())!='\n'){
		if(ch>='0'&&ch<='9'){
			a++;
		}else if(ch==' '){
			b++;
		}else{
			c++;
		}
	}
	printf("blank = %d, digit = %d, other = %d",b,a,c);
	return 0;
}
