#include<stdio.h>
#include<string.h>
int main(void){
	int i,j,str,sum,p;
	char a[101];
    gets(a);
	str=strlen(a);
	printf("%c",a[1]);
	a[str]=' ';
	for(i=0;i<=str;i++){
		if(a[i]!=' '){
			sum++;
		}else {
			p=i-1;
			for(j=sum;j>0;j--){
				printf("%c",a[p--]);
			}
			printf("\n");
		}
		sum=0;
	}
	return 0;
}
