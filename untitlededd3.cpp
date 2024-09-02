#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct person {
	char name[11];
	int a;
	int b;
	int c;
	double aver;
};
void Max(	struct person *pr , int n) {
	int i, j;
     struct person t;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n-i; j++) {
		  if((pr+j)->aver<(pr+j+1)->aver){
			  t=*(pr+j);
			  *(pr+j)=*(pr+j+1);
			  *(pr+j+1)=t;
		  }
			}
		}
	}


int main(void) {
	int i, j, n, t;
	struct person person[101];
     while(scanf("%d",&n)!=EOF){
	for (i = 0; i < n; i++) {
		scanf("%s %d %d %d", person[i].name, &person[i].a, &person[i].b, &person[i].c);
	}
	for (i = 0; i < n; i++) {
		person[i].aver = (double)(person[i].a + person[i].b + person[i].c) /3.0;
	}
	Max(person, n);
	for(i=0;i<n;i++){
		printf("%s %d %d %d %d %.2lf\n",person[i].name,person[i].a,person[i].b,person[i].c,person[i].aver);
	}
	 }
	return 0;
}
