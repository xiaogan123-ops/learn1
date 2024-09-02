#include<stdio.h>
#include<string.h>
int main(void){
	int i,j,str,flog;
	char a[101];
	gets(a);
	str=strlen(a);
	for(i=0;i<str/2;i++){
		if(a[i]==a[str-i-1]){
			flog=1;
		}else {
			flog=0;
			break;
		}
	}
	if(flog){
		printf("yes");
	}else printf("no");
	return 0;
}
