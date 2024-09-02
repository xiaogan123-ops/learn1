#include<stdio.h>
int Max(int a, int b, int c) {
	int i, j,t;
	int d[3] = {a,b,c};
	for (i = 1; i < 3; i++) {
		for (j = 0; j < 3 - i; j++) {
			if (d[j] > d[j + 1]) {
				t = d[j];
				d[j] = d[j + 1];
				d[j + 1] = t;
			}
		}
	}
	return d[2];
}
int main(void) {
	int a, b, c, max1 = 0;
	int max2 =0,max3 = 0;
	double total=0;
	scanf("%d %d %d", &a, &b, &c);
	max1 = Max(a, b, c);
	max2 = Max(a + b, b, c);
	max3 = Max(a, b, b + c);
	total = (double)((max1 * 1.0) / (max2 * max3));
	printf("%.3lf", total);
	return 0;
}
