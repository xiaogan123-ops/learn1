#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, j = 0;
	cin >> n;
	int b;
	int a[200 * 200 + 1];
	bool now = 0;
	while (cin >> b) {
		for (int i = b + j; i > j; i--) {
			a[i] = now;
		}
		j += b;
		now = !now;
	}
	 j = 1;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cout << a[j];
			j++;
		}
		cout << endl;
	}
	return 0;
}