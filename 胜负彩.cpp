#include<stdio.h>
int main(void){
	int i,j;
	double total;
	char b[3];
	double a[3][3],c[3];
	for(i=0;i<3;i++){
		for( j=0;j<3;j++){
			scanf("%lf",&a[i][j]);
		}
	}
	for( i=0;i<3;i++){
		if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
			b[i]='W';
			c[i]=a[i][0];
		}else if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]){
			b[i]='T';
			c[i]=a[i][1];
		}else if(a[i][2]>a[i][1]&&a[i][2]>a[i][0]){
			b[i]='L';
			c[i]=a[i][2];
		}
	}
	total=(c[0]*c[1]*c[2]*0.65-1)*2;
	for( i=0;i<3;i++){
		printf("%c ",b[i]);
	}
	printf("%.2lf",total);
	return 0;
}
