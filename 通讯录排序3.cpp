#include<stdio.h>
struct person{
	char name[11];
	int birth;
	char phone[18];
};
int main(void){
	int i,n,t;
	struct person person[10];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %d %s",person[i].name,&person[i].birth,person[i].phone);
	}
	for(i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
		if(person[j].birth>person[j+1].birth){
			t=person[j].birth;
			person[j].birth=person[j+1].birth;
			person[j+1].birth=t;
		}
	}
	 }
	for(i=0;i<n;i++){
		printf("%s %d %s\n",person[i].name,person[i].birth,person[i].phone);
	}
	return 0;
}
