#include<stdio.h>

struct person{
	char name[11];
	int birth;
	char phone[18];
};
void move(struct person *p,int n);
int main(void){
	int n,i;
	struct person person[10];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %d %s",person[i].name,&person[i].birth,person[i].phone);
	}

	move(person,n);
	for(i=0;i<n;i++){
		printf("%s %d %s\n",person[i].name,person[i].birth,person[i].phone);
	}
	return 0;
}
void move(struct person *p,int n){
	int i,j;
	struct person t;
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if((p+j)->birth>(p+j+1)->birth){
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t;
			}
		}
	}
}
