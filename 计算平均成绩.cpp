#include<stdio.h>
#include<stdlib.h>
struct person{
	char numble[6];
	char name[11];
	int score;
};
int main(void){
	int n,i,sum=0;
	double average=0;
	struct person person[10];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %s %d",person[i].numble,person[i].name,&person[i].score);
	}
	for(i=0;i<n;i++){
		sum+=person[i].score;
	}
	average=sum/n;
	printf("%.2lf\n",average);
	for(i=0;i<n;i++){
		if(person[i].score<average){
			printf("%s %s\n",person[i].name,person[i].numble);
		}
	  }
	return 0;
}
