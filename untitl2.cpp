#include<stdio.h>
#include<string.h>
int main(void) {
	int i = 0, j,t = 0, sum = 0, max = 0, mix = 100, x = 0, y = 0, x1 = 0, y1 = 0;
	char a[10000];
	gets(a);
	t = strlen(a);
	a[t] = ' ';
	for (i = 0; i <= t; i++) {
		if (a[i] != ' ' && a[i] != ',' && a[i] != '.') {
			sum++;
		}
		else if (sum > 0)
		{
			
			if (sum> max) {
				max = sum;
				x = i -sum ;
				y = i - 1;
			}
			if (sum < mix) {
				mix = sum;
				x1 = i - sum;
				y1 = i - 1;
			}
			sum = 0;
		}
		
	}
	for (i = x; i <= y; i++) {
		printf("%c", a[i]);
		
	}
	printf("\n");
	for (j = x1; j <= y1; j++) {
		printf("%c", a[j]);
	}
	return 0;
}
