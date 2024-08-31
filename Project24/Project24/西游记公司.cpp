#include<bits/stdc++.h>
using namespace std;

int main7() {
	long long  a, b, c, d, e, f;
	char s;
	long long n;
	cin >> a >> s >> b >> s >> c >> d >> s >> e >> s >> f;
	cin >> n;
	cout << ((d-a) * 3600 + (e-b) * 60 + f-c) * n;
	return 0;
}