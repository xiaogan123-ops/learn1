#include<bits/stdc++.h>
using namespace std;
int  mingobeishu(int n, int m) {
	int t;
	while (m) {
		t = n%m;
		n = m;
		m = t;
	}
	return n;
}
int main1() {
	int  k;
	int  a, b, e, d;
	char c;
	cin >> a >> c >> b;
	cin >> e >> c >> d;
	int sum1, sum2 = 0;
	sum1 = a * e;
	sum2 = b * d;
	k=mingobeishu(sum1, sum2);
	sum1 /= k;
	sum2 /= k;
	cout << sum2 << " " << sum1;
	return 0;
}
