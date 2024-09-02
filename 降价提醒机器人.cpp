#include<stdio.h>
struct numble{
	double score;
};
int main(void){
	int n,m;
	scanf("%d %d",&n,&m);
	struct numble numble[100];
	for(int i=0;i<n;i++){
		scanf("%lf",&numble[i].score);
	}
	for(int i=0;i<n;i++){
		if(numble[i].score<m){
			printf("On Sale! %.1lf\n",numble[i].score);
		}
	}
	return 0;
}
