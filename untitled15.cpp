#include<stdio.h>
#include<string.h>

char num(char letter,int move){
	int i=letter+move;
	if((i>='a'&&i<='z' )||(i>='A'&&i<='Z')) 
		return (char)i;
	else if((i<'a')||(i<'A'))
		return (char)(i+26);
	else return(char)(i-26);
}

int main(void)
{
	char str[80],str1[80];
	int length, n;
	gets(str);
	scanf("%d",&n);
	n=n%26;
	length=strlen(str);
	for(int i=0;i<length;++i){
		if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
			str1[i]=num(str[i],n);
		else str1[i]=str[i];
	}
	str1[length]='\0';
	puts(str1);
	return 0;
	
}
