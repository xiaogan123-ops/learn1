#include<bits/stdc++.h>
using namespace std;
int min1 = 0;
int main5() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	min1 = abs(a - b);
	if (abs(a - c) + abs(b - d) < min1) {
		min1 = abs(a - c) + abs(b - d);
	}
	if (abs(a - d) + abs(b - c) < min1) {
		min1 = abs(a - d) + abs(b - c);
	}
	cout << min1;
	return 0;
}