#include<stdio.h>
#include<string.h>
int main(void){
	char a[51];
	int len,i;
	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;i++){
		if(a[i]>='a'&&a[i]<='z'){
			a[i]=((a[i]-'a')+3+26)%26+'a';
		}else {
			a[i]=((a[i]-'A')+3+26)%26+'A';
		}
	}
    for(i=0;i<len;i++){
		if(a[i]>='a'&&a[i]<='z'){
			a[i]=a[i]-'a'+'A';
		}else a[i]=a[i]-'A'+'a';
	}
	for(i=len-1;i>=0;i--){
		printf("%c",a[i]);
	}
	return 0;
}
