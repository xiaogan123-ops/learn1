#include<stdio.h>
void move(int (*p)[3]){
	int i,j,t;
	for(i=0;i<3;i++){
		for(j=0;j<i;j++){
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
			scanf("%d",&a[i][j]);
		}
	}
	move(a);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(j==2){
				printf("%d",a[i][j]);
			}else 
			printf("%d ",a[i][j]);
		}

		printf("\n");
	}
	return 0;
}
