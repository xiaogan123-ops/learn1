#include<stdio.h>
#include<Windows.h>
int main()
{
	system(" color 0c");
	printf("遇见你是一件很开心的事情,加油，小美女！！！\n");
	
	float x,y,a;
	
	for(y=1.5f;y>-1;y-=0.1f)
	{
		for(x=-1.5f;x<1.5f;x+=.05f){
			a=x*x+y*y-1;
			putchar(a*a*a-x*x*y*y*y<0.0f?'x':' ');
		}
		
		Sleep(150); 
		putchar('\n');  
	}
	
	return 0;
}
