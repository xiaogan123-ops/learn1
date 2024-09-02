#include<stdio.h>
#include<string.h>
struct student{
	char name[11];
	int a[3];
	double aver;
};
void max(struct student *p,int n);
int main(void){
	int i,n;
	while(scanf("%d",&n)!=EOF){
		struct student su[100];
		for(i=0;i<n;i++){
			scanf("%s %d %d %d",su[i].name,&su[i].a[0],&su[i].a[1],&su[i].a[2]);
			su[i].aver=(double)(su[i].a[0]+su[i].a[1]+su[i].a[2])/3.0;
		}
		max(su,n);
		for(i=0;i<n;i++){
			printf("%s %d %d %d %.2lf",su[i].name,su[i].a[0],su[i].a[1],su[i].a[2],su[i].aver);
			if(i!=n-1)  printf("\n");
		}
		printf("\n");
	}
	return 0;
}
void max(struct student *p,int n){
	int i,j;
	struct student t;
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if((p+j)->aver < (p+j+1)->aver){
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t;
			}else if(strcmp((p+j)->name,(p+j+1)->name)!=-1&&(p+j)->aver==(p+j+1)->aver){
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t;
			}
		}
	}
}
