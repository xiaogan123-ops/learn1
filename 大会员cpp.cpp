#include<stdio.h>
struct person{
	char sum[10];
	char name[21];
	int numble;
	char a;
};
int main(void){
	int n,i,total=0;
	struct person person[11];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %s %d",person[i].sum,person[i].name,&person[i].numble);
	}
	for(i=0;i<n;i++){
		if(person[i].numble>=10000){
			person[i].a='S';
			total++;
		}else if(person[i].numble>=5000){
			person[i].a='B';
		}else if(person[i].numble>=1000){
			person[i].a='C';
		}else person[i].a='D';
	}
	for(i=0;i<n;i++){
		printf("%s %s %c\n",person[i].sum,person[i].name,person[i].a);
	}
	printf("%d",total);
	return 0;
}
