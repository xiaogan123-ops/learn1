#include<stdio.h>
void move(int (*pointer)[3]);
int main(void){
	int i,j;
	int a[3][3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int (*p)[3];
	p=a;
	move(p);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d",*(*(p+i)+j));
			if(j!=2){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
	
}
void move(int (*pointer)[3]){
	int i,j,t;
	for(i=0;i<3;i++){
		for(j=0;j<i;j++){
			t=*(*(pointer+i)+j);
			*(*(pointer+i)+j)=*(*(pointer+j)+i);
			*(*(pointer+j)+i)=t;
		}
	}
}
