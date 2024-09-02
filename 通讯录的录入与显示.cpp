#include<stdio.h>
struct stu {
	char name[11];
	char birth[11];
	char sex[2];
	char numble[17];
	char numble1[17];
} person[100];
int main(void) {
	int i, n;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%s %s %s %s %s", person[i].name, person[i].birth, person[i].sex, person[i].numble, person[i].numble1);
	}
	int a, k;
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf("%d", &a);
		if (a < n && a >= 0) {
			printf("%s %s %s %s %s\n", person[a].name, person[a].birth, person[a].sex, person[a].numble, person[a].numble1);
		} else printf("Not Found\n");
	}
	return 0;
}
