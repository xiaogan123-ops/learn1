#include<bits/stdc++.h>
using namespace std;
bool sushu(int n) {
	if (n == 1) {
		return 0;
	}
	if (n == 2) {
		return 1;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main2() {
	int n;
	cin >> n;
	int a[10000] = { 0 };
      for (int i = 4; i <= n; i += 2) {
		int sum = 0;
		for (int j = 2; j < i-1; j++) {
			if (sushu(j)) {
				a[sum] = j;
				sum++;
			}
		}
		sort(a + 0, a + sum);
		if (sum == 1) {
			cout << i << "=" << a[0] << "+" << a[0];
		}
		else {
			for (int k = 0; k < sum; k++) {
				int making = 0;
				for (int t = sum - 1; t >= 0; t--) {
					if (a[k] + a[t] == i) {
						cout << i << "=" << a[k] << "+" << a[t];
						making = 1;
						break;
					}
					
				}
				if (making == 1) {
					break;
				}
			}
		}
		cout << endl;
	}
	  return 0;
}