#include<bits/stdc++.h>
using namespace std;
int a, b, c;

int main1() {
	string s;
	cin >> s;
	int total = 0;
	for (int i = 0; i < s.length(); i+=5) {
		int t;
		char t1=s[i+3],t2=s[i];
		if (s[i + 3] == 'a') {
			t = a;
		}
		else if (t1 == 'b') {
			t = b;
		}
		else if (t1 == 'c') {
			t = c;
		}
		else t = t1 - '0';
		if (t2 == 'a') {
			a = t;
		}
		if (t2 == 'b') {
			b = t;
		}
		if (t2 == 'c') {
			c = t;
		}
	}
	
	cout << a << " " << b << " " << c;
	return 0;
}