#include<stdio.h>
#include<string.h>
int main(void)
{
	int n,b[80],c[100],d[100],e[100],f[100];
	scanf("%d",&n);
	char a[80];
     while(n--){
		int count=0,total=0,face=0,other=0;
		gets(a);		
		b[n]=strlen(a);	
		 if(b[n]<6){
			 continue;
		 }else for(int i=0;i<b[n];i++){
		if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
			c[n]=count++;
		}else if(a[i]=='.'){
			d[n]=total++;
		}else if(a[i]>='1'&&a[i]<='9'){
			e[n]=face++;
		}else  f[n]=other++;
	}
	 }
		 for(int i=0;i<n;i++){
			 if(b[i]<6)
				 printf("Your password is tai duan le.");
				 else if(f[n]!=0)
					 printf("Your password is tai luan le.");
					 else if(c[i]!=0&&e[i]==0&&d[i]>=0)
						 printf("Your password needs shu zi.");
			else if(e[i]!=0&&c[i]==0&&d[i]>=0)
				printf("Your password needs zi mu.");
			 else printf("Your password is wan mei.");
}
	return 0;
}
