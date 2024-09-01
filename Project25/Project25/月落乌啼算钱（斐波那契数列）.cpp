#include<bits/stdc++.h>
using namespace std;
int main7() {
	int n;
	cin >> n;
	double a, b;
	a = pow((1 + sqrt(5)) / 2, n);
	b = pow((1 - sqrt(5)) / 2, n);
	double sum = 0;
	sum = (a - b) / sqrt(5);
	printf("%0.2f", sum);
	return 0;
}