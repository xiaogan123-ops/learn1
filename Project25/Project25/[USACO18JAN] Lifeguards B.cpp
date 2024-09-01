#include<bits/stdc++.h>
using namespace std;
int max1 = 0;
int main8() {
	int n,making=0;
	cin >> n;
	int b, c;
	vector<pair<int, int>> v;
	int a[10000] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> b >> c;
		v.push_back(make_pair(b, c));
	}
	for (int j = 0; j < n; j++) {
		int sum = 0;
		for (int i = 0; i < 10000; i++) {
			a[i] = 0;
		}
		
		for (int i = 0; i < n; i++) {
			if (i != making) {
				for (int k = v[i].first; k < v[i].second; k++) {
					a[k]++;
				}
			}
		}
		making++;
		for (int i = 0; i < 10000; i++) {
			if (a[i] != 0) {
				sum++;

			}
		}
		if (sum > max1) {
			max1 = sum;
		}
	}
	cout << max1;
	return 0;
}