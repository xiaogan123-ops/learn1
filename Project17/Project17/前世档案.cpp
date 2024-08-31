#include<iostream>
#include<cmath>
using namespace std;
int main5() {
	int a[100] = {0};
	int n, m, right,mid=0;
	cin >> n >> m;
	right = pow(2, n);
	char ch;
	for (int i = 0; i < m; i++) {
		int left = 1;
		right = pow(2, n);
		while (left < right) {
			cin >> ch;
			mid = (right + left) / 2;
			if (ch == 'y') {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		a[i] = left;
	}
	for (int i = 0; i < m; i++) {
		cout << a[i] << endl;
	}
	return 0;
}