#include <stdio.h>
#include <math.h>
int isprime(int N)//素数判定;
{    if(N<=1) return 0;
	else for(int i=2 ; i<=sqrt(N) ; i++)
		if( N%i == 0)
			return 0;
	return 1;
}
int main()
{
	int L,K;
	scanf("%d %d",&L,&K);
	char str[L+1];
	scanf("%s",str);
	for(int i=0 ; i<=L-K ; i++)
	{
		int N=0;//N用于装数;
		for(int j=i ; j<K+i ; j++)//转换为整形;
			N = N*10 + str[j]-'0' ;
		if( isprime(N) )//若为素数-
		{   
			for(int j=i ; j<K+i ; j++)
				printf("%c",str[j]);
			return 0;
		}
	}
	printf("404");
}

