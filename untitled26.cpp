#include<stdio.h>
int main()
{
	int i,a,b,c[7],max=0,n;//定义数组 
	for(i=0;i<7;i++)
	{
		scanf("%d %d\n",&a,&b);//输入津津在学校上课的时间和妈妈安排她上课的时间
		c[i]=a+b; //津津在学校上课的时间和妈妈安排她上课的时间求和 
	}
	for(i=6;i>=0;i--)//倒着找最先不高兴日期
	{
		if(max>c[i])max=max;//找出最大值 
		else if(max<=c[i])max=c[i];//找出最大值
	}
	for(i=6;i>=0;i--)
	{
	       if(max>8){
			   if(max==c[i]) n=i;
		   }//找到津津不高兴的日期 
		else   printf("%d\n",0);//若无不高兴日期，则输出0
	}
	
	printf("%d\n",n+1);//输出津津不高兴的日期 
	return 0;
}
