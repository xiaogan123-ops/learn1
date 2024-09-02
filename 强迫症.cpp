#include<stdio.h>
#include<string.h>
int main(void){
	int i,str,total=0;
	char a[7];
	scanf("%s",a);
	str=strlen(a);
	if(str==4){
		total=(a[0]-'0')*10+(a[1]-'0');
		if(total < 22){
			for(i=0;i<4;i++){
				if(i==0){
					printf("20");
				}
				if(i==2){
					printf("-%c",a[i]);
				}else printf("%c",a[i]);
			}
		}else{
		for(i=0;i<4;i++){
			if(i==0){
				printf("19");
			}
			if(i==2){
				printf("-%c",a[i]);
			}else printf("%c",a[i]);
		}	
		}		
	}else {
		for(i=0;i<6;i++){
			if(i==4){
				printf("-%c",a[i]);
			}else printf("%c",a[i]);
		}
	}
	return 0;
}
