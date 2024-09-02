#include<stdio.h>
#include<string.h>
int main(void){
	int n,i,len;
	char a[80];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		gets(a);
	}
	for(i=0;i<n;i++){
		int count=0,sum=0,total=0,other=0;
		len=strlen(a);
		if(len<6){
			printf("Your password is tai duan le.\n");
		    break;}
		else for(i=0;i<len;i++){
			if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
				count++;
			}else if(a[i]>='1'&&a[i]<='9'){
				sum++;
			}else if(a[i]=='.'){
				total++;
			}else other++;
		}
		if(other!=0){
			printf("Your password is tai luan le.\n");
		}else if(count==0&&sum!=0){
			printf("Your password needs shu zi.\n");
		}else if(sum!=0&&count==0){
			printf("Your password needs zi mu.\n");
		}else 	printf("Your password is wan mei.\n");
	}
	
}
