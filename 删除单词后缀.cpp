#include<stdio.h>
#include<string.h>
int main(void) {
	int i, len;
	char a[33];
	scanf_s("%s", a);
	len = strlen(a);
	if (len != 2 && a[len - 2] == 'e' && a[len - 1] == 'r') {
		a[len - 2] = '\0';
		printf("%s", a);
	}
	else if (len != 2 && a[len - 2] == 'l' && a[len - 1] == 'y') {
		a[len - 2] = '\0';
		printf("%s", a);
	}
	else if (len != 3 && a[len - 3] == 'i' && a[len - 2] == 'n' && a[len - 1] == 'g') {
		a[len - 3] = '\0';
		printf("%s", a);
	}
	return 0;
}
