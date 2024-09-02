#include<stdio.h>
#include<string.h>
int main(void){
	int i,n;
	char a[80],b[80];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		scanf("%s",a);
		if(i==0)
			strcpy(b,a);
		if(strlen(b)<strlen(a))
			strcpy(b,a);
	}
	printf("The longest is: %s",b);
	return 0;
}

