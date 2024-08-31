#include<bits/stdc++.h>
using namespace std;
int sum=1, max1 = 0;
void day(vector<int> &v) {
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i + 1] > v[i]) {
			sum++;
		}
		else sum = 1;
		if (sum > max1) {
			max1 = sum;
		}
	}
}
int main3() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	day(v);
	cout << max1;

	return 0;
}