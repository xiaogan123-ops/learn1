#include<stdio.h>
#include<math.h>
int face(int n) {
	if (n <= 1)   return 0;
	else for (int i = 2; i < sqrt(n); i++)
		if (n % i == 0)
			return 0;
	return 1;
}
int main() {
	int k, l;
	scanf("%d %d", &l, &k);
	char str[l + 1];
	scanf("%s", str);
	for (int i = 0; i <= l - k; i++) {
		int n = 0;
		for (int j = i; j < k + i; j++)
			n = n * 10 + str[j] - '0';
		if (face(n))  {
			for (int j = i; j < k + i; j++)
				printf("%c", str[j]);
			return 0;
		}
	}
	printf("404");
}
