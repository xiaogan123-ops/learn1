#include<stdio.h>
int main(void){
	int ch,i,a=0,b=0,c=0;
	   for(i=1;(ch=getchar())!='\n';i++){
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
