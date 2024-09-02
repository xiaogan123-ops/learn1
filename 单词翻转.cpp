#include<stdio.h>
int main(void) {
	int str, i = 0, p, j, sum = 0;
	char a[101];
	while ((a[i] = getchar()) != '\n') {
		i++;
	}
	str = i;
	a[str] = ' ';
	for (j = 0; j <= str; j++) {
		if (a[j] != ' ') {
			sum++;
		} else {
			p = j - 1;
			for (; sum > 0; sum--) {
				printf("%c", a[p--]);
			}
			sum = 0;
			  if(j!=str)  printf("\n");
		}
	}
	return 0;
}
