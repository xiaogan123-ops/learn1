#include<bits/stdc++.h>
using namespace std;

int sum2 = 0, min1 = 0;
void compare(vector<int>& v, int m) {
	
	for (int i = 0; i < m; i++) {
		sum2 += v[i];
	}
	min1 = sum2;
	for (int i = m; i < v.size(); i++) {
		sum2 += v[i] - v[i - m];
		if (sum2 < min1) {
			min1 = sum2;
		}

	}
	



}
int main5() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	compare(v, m);
	cout << min1;
	return 0;
}