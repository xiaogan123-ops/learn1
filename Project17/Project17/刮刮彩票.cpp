#include<iostream>
using namespace std;
int main6() {
	int i, j, n, sum = 0, other = 0, row = 0,m;
	int a[4][4];
	int b[10] = {1,2,3,4,5,6,7,8,9};
	for (i = 1; i < 4; i++) {
		for (j = 1; j < 4; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				other = i;
				row = j;
			}
		}
	}
	for (i = 1; i < 4; i++) {
		for (j = 1; j < 4; j++) {
			for (int k = 0; k < 9; k++) {
				if (a[i][j] == b[k]) {
					b[k] = 10;
				}
			}
		}
	}
	for (i = 0; i < 9; i++) {
		if (b[i] != 10) {
			a[other][row] = b[i];
		}
	}
	for (i = 0; i < 3; i++) {
		cin >> n >> m;
		cout << a[n][m];
		cout << endl;
	}
	cin >> n;
	switch (n) {
	case 1:sum = a[1][1] + a[1][2] + a[1][3];
		break;
	case 2:sum = a[2][1] + a[2][2] + a[2][3];
		break;
	case 3:sum = a[3][1] + a[3][2] + a[3][3];
		break;
	case 4:sum = a[1][1] + a[2][1] + a[3][1];
		break;
	case 5:sum = a[1][2] + a[2][2] + a[3][2];
		break;
	case 6:sum = a[1][3] + a[2][3] + a[3][3];
		break;
	case 7:sum = a[1][1] + a[2][2] + a[3][3];
		break;
	case 8:sum = a[1][3] + a[2][2] + a[3][1];
		break;
	default:
		break;
	}
	int c[25] = { 0,0,0,0,0,0,10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600 };

	cout << c[sum];
	return 0;
}