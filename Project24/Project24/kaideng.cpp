#include<bits/stdc++.h>
using namespace std;
int t,max2=0;
int a1[2000000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 200000; i++) {
		a1[i] = 0;
	}
	while (n--) {
		double b;
		int c;
		cin >> b >> c;
		for (int i = 1; i <= c; i++) {
			t = i * b;
			a1[t]++;
			if (t > max2) {
				max2 = t;
			}
		}
	}
	
	for (int i = 0; i <= max2; i++) {
		if (a1[i] != 0) {
			if (a1[i] % 2 != 0) {
				cout << i;
				return 0;
			}
		}
	}
	
	return 0;
}