#include<stdio.h>
int main(void){
	int i=0,j,str;
	char a[101];
	while((a[i]=getchar())!='\n'){
		i++;
	}
	a[i]='\0';
	j=i-1;
	i=0;
     while(i<j){
		 if(a[i]!=a[j]){
			 break;
		 }
		 i++;
		 j--;
	 }
	if(i<j){
		printf("no");
	}else printf("yes");
	return 0;
}
