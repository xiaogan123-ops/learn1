#include<stdio.h>
struct person{
	int name;
	int score[3];
	double aver;
};
int main(void){
	int i,n;
	struct person person[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %d %d %d",person[i].name,&person[i].score[0],&person[i].score[1],&person[i].score[2]);
	}
	for(i=0;i<n;i++){
		person[i].aver=(double)(person[i].score[1]+person[i].score[2]+person[i].score[0])/3.0;
	}
	printf("%d",person[0].aver);
	return 0;
}
