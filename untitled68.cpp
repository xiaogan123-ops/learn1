#include<stdio.h>
#include<stdlib.h>
struct person{
	char a[4];
	char name[21];
	int num;
	char b;
};
int main(void){
	int n,i,sum=0;
	struct person person[10];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %s %d",person[i].a,person[i].name,&person[i].num);
	}
	for(i=0;i<n;i++){
		if(person[i].num>=90){
			sum++;
			person[i].b='S';
		}else if(person[i].num>=80&&person[i].num<90){
			person[i].b='A';
		}else if(person[i].num>=70&&person[i].num<80){
			person[i].b='B';
		}else person[i].b='C';
	}
	for(i=0;i<n;i++){
		printf("%s %s %c\n",person[i].a,person[i].name,person[i].b);
	}
	
	printf("%d",sum);
	return 0;
}
