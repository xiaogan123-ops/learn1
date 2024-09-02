#include <stdio.h>
int main(){
	int a[50], i, n;
	int *p=a;
	while(scanf("%d", &n) != EOF){
		a[i] = n;
		i++;
	}
	for(int j = i - 1 ; j >= 0; j--){
		if(j == i - 1) printf("%d", *(p + j));
		else printf(" %d", *(p + j));
	}
	return 0;    
}
