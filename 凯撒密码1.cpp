#include<stdio.h>
#include<string.h>
int main(void){
	int i,offset,str;
	char a[80];
	gets(a);
	str=strlen(a);
	scanf("%d",&offset);
	offset=offset%26;
	for(i=0;i<strlen(a);i++){
		if(offset>0){
			if(a[i]>='a'&&a[i]<='z'){
				if(a[i]-'a'+offset<26){
					a[i]=a[i]+offset;
				}else a[i]=(a[i]-'a'+offset)%26;
			}else if(a[i]>='A'&&a[i]<='Z'){
				if(a[i]-'A'+offset<26){
					a[i]=a[i]+offset;
				}else a[i]=(a[i]-'A'+offset)%26;
			}else a[i]=a[i];
		}else {
			if(a[i]>='a'&&a[i]<='z'){
				if(a[i]-'a'+offset>0){
					a[i]=a[i]+offset;
				}else a[i]=(a[i]-'a'+offset)%26+26;
			}else if(a[i]>='A'&&a[i]<='Z'){
				if(a[i]-'A'+offset>0){
					a[i]=a[i]+offset;
				}else a[i]=(a[i]-'A'+offset)%26+26;
			}else a[i]=a[i];
		}
	}
	a[i]='\0';
	printf("%s",a);
	return 0;
}
