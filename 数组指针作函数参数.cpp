#include<stdio.h>
void move(int *pr,int m,int n);
void tota(int *pr,int total[],double aver[],int n,int m);
void Printf(int total[],double aver[],int m);
int main(void){
	int m,n;
	scanf("%d",&m);
	scanf("%d",&n);
	int total[30];
	double aver[30];
    int a[30][5];
	move(*a,m,n);
	tota(*a,total,aver,n,m);
	Printf(total,aver,m);
	return 0;	
}
void move(int *pr,int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&pr[i*n+j]);
		}
	}
}
void tota(int *pr,int total[],double aver[],int n,int m){
	int i,j;
	for(i=0;i<m;i++){
		total[i]=0;
		for(j=0;j<n;j++){
			total[i]=total[i]+pr[i*n+j];
		}
		aver[i]=(double)total[i]/n;
	}
}
void Printf(int total[],double aver[],int m){
	int i;
	for(i=0;i<m;i++){
		printf("%d %.1lf\n",total[i],aver[i]);
	}
}
