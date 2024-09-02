#include<stdio.h>
#include<stdlib.h>
struct person{
	char numble[17];
	int a;
	int b;
};
int main(void){
	int n,m,i,num[1001];
	struct person person[1001];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %d %d",person[i].numble,&person[i].a,&person[i].b);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&num[i]);
	}for(i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(num[i]==person[j].a){
				printf("%s %d\n",person[j].numble,person[j].b);
			}
		}
	}
	return 0;
	
}
