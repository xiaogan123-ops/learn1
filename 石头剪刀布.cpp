#include<stdio.h>
#include<string.h>
#define Lin1  strlen(a)
#define Lin2  strlen(b)
int main(void) {
	int i, n;
	char str[101][10], a[10], b[10], c[5] = {"Tie"}, d[10] = {"Player1"}, e[10] = {"Player2"};
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %s",a,b);
		if (strcmp(a, b) == 0) {
			strcpy(str[i], c);
		}
		else if (Lin1 == 4 && Lin2 == 8 || Lin1 == 5 && Lin2 == 4 || Lin1 == 8 && Lin2 == 5) {
			strcpy(str[i], d);
		}
		else strcpy(str[i], e);
	}
	for (i = 0; i < n; i++) {
		printf("%s\n", str[i]);
	}
	return 0;
}
