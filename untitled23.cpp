#include<stdio.h>
#include<string.h>
int main(){
	int i,offset,length;
	char a[80];
     gets(a);
	scanf("%d\n",&offset);
	offset=offset%26;
	length=strlen(a);
	for( i=0;i<length;i++){
		if(a[i]>='a'&&a[i]<='z'){
			if(a[i]-'a'+offset>=1 && a[i]-'a'+offset<=26){
				a[i]=a[i]+offset;
			}else if(a[i]-'a'+offset>26){
				a[i]=a[i]+offset-26;
			}else a[i]=a[i]+26+offset;
		}
		else if(a[i]>='A'&&a[i]<='Z'){
			if(a[i]-'A'+offset>=1 && a[i]-'A'+offset<=26){
				a[i]=a[i]+offset;
			}else if(a[i]-'A'+offset>26){
				a[i]=a[i]+offset-26;
			}else a[i]=a[i]+26+offset;
		}else a[i]=a[i];
	}
	a[i]='\0';
    printf("%s",a);
	return 0;
}
