#include<stdio.h>
#include<math.h>
void size(double *p,int n);
int main(void){
	int n,i;
	scanf("%d",&n);
	double a[n];
	for(i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}
	size(a,n);
	return 0;
}
void size(double *p,int n){
	int i,j,t;
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(*(p+j)<*(p+j+1)){
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t;
			}
		}
	}
	for(i=0;i<n;i++){
		if(i!=n-i){
			printf("%.1lf ",*(p+i));
		}else printf("%.2lf",*(p+i));
	}
}
