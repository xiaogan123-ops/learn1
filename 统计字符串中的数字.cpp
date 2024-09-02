#include<stdio.h>
int main(void){
	int i,j,flog=0;
	char a[1111];
	i=0;
	while((a[i]=getchar())!='\n'){
		i++;
	}
	for(i=0;a[i]!='\n';i++){
		for(j=0;a[j]!='\n';j++){
			if(a[i]==a[j]&&i!=j){
				flog=1;
			}
		}
		if(flog==0){
			printf("%c",a[i]);
			break;
		}else if(flog==1&&a[i+1]=='\n'){
			printf("no");
		}
		flog=0;
	}
	return 0;
}
