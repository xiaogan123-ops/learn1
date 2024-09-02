#include <stdio.h>
void sb(int a[],int n);
int main()
{
	int a[101]={0};
	int cont=0;
	int p;
	for(int i=0;;i++)
	{
		scanf("%d",&a[i]);
		cont++;
		if(a[i]<0)
			break ;
	}
	if(cont>3){
		sb(a,cont-1);//由于最后输入的负数不算； 
		printf("%d %d %d",a[0],a[1],a[2]);}
	else if(cont==3)
	{
		if(a[0]<a[1]){
			p=a[0];a[0]=a[1];a[1]=p;}
		printf("%d %d #",a[0],a[1]);
	}
	else if(cont==2)
		printf("%d # #",a[0]);
	else
		printf("# # #");
	
	return 0;
}

void sb(int a[],int n)//将数组从大到小排；然后输出a[0] a[1] a[2]; 
{

		int i,j,sum;
		for(i=1;i<n;i++){
			for(j=0;j<n-i;j++){
				if(a[j]<a[j+1]){
					sum=a[j];
					a[j]=a[j+1];
					a[j+1]=sum;
				}
			}
		}
}

