#include<stdio.h>
void move(int (*p)[3]){
    int i,j,t;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
				t=*(*(p+i)+j);
				*(*(p+i)+j)=*(*(p+j)+i);
				*(*(p+j)+i)=t;
		}
	}
}
int main(void){
	int i,j;
	int a[3][3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",a[j]);
		}
	}
	move(a);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
