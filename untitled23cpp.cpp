#include<stdio.h>
#include<string.h>
int main(void){
	int i,offset,total;
	char a[80];
	gets(a);
	scanf("%d",&offset);
	offset=offset%26;
	total=strlen(a);
	for(i=0;i<total;i++){
		if(a[i]>='a'&&a[i]<='z'){
			if(offset>=0){
				a[i]=((a[i]-'a')+offset)%26+'a';
			}else a[i]=((a[i]-'a')+offset+26)%26+'a';
		}
		else if(a[i]>='A'&&a[i]<='Z'){
				if(offset>=0){
					a[i]=((a[i]-'A')+offset)%26+'A';
				}else a[i]=((a[i]-'A')+offset+26)%26+'A';
		}else a[i]=a[i];
	}
	puts(a);
	return 0;
}
