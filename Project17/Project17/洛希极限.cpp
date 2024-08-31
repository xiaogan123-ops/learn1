#include<iostream>
#include<cstdio>
using namespace std;
int main0() {
	double a, b, c;
	double sum = 0;
	cin >> a >> b >> c;
	if (b == 0) {
		sum = a * 2.455;
	}
	else sum = a * 1.26;
	if (sum <= c) {
		printf("%.2lf", sum);
		cout<<" " << "^_^";
	}
	else {
		printf("%.2lf", sum);
		cout<< " " << "T_T";
	}
	return 0;
}