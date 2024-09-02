#include<iostream>
#include<cstring>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a[10] = { 0 },sum=0,t=0;
	int b[10] = { 0 };
	int c[11] = { 0 };
	for (int i = 0; i < 11; i++) {
		a[s[i] - '0'] = 1;
	}
	for (int j = 0; j < 10; j++) {
		if (a[j] != 0) {
			b[j] = j;
			sum++;
		}
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10 - i; j++) {
			if (b[j] < b[j + 1]) {
				t = b[j];
				b[j ] = b[j+1];
				b[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < sum; j++) {
			if (s[i]-'0' == b[j]) {
				c[i] = j;
			}
		}
	}
	cout << "int[] arr = new int[]{";
	for (int i = 0; i < sum; i++) {
		if (i != sum - 1) {
			cout << b[i] << ",";
		}
		else cout << b[i] << "};"<<endl;
	}
	cout << "int[] index = new int[] {";
	for (int i = 0; i < 11; i++) {
		if (i != 10) {
			cout << c[i] << ",";
		}
		else cout << c[i] << "};" << endl;
	}
	return 0;
}
