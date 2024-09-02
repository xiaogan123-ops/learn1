#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);//输出n
	getchar();
	char a[81];
	
	int len;
	while(n--)
	{	int cha=0,num=0,point=0,other=0;
		gets(a);
		len=strlen(a);
		if(len<6){
			printf("Your password is tai duan le.\n");
			continue;}
		else for(int i=0; i<len; i++)
		{
			if(a[i]>='0' && a[i]<='9')num++;
			else if((a[i]>='a'&&  a[i]<='z' )|| (a[i]>='A'&& a[i]<='Z'))cha++;
			else if(a[i]=='.')point++;
			else other++;
		}
		if(other!=0)printf("Your password is tai luan le.\n");
		else if(cha!=0 && num==0)printf("Your password needs shu zi.\n");
		else if(cha==0 && num!=0)printf("Your password needs zi mu.\n");
		else printf("Your password is wan mei.\n");
	}
	return 0;
}

