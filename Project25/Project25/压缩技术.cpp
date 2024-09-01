#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;
int main4() {
	vector<string> v;
	string s;
	while (cin >> s) {
		v.push_back(s);
	}
	cout << v.size() ;
	string s1;
	for (auto i : v) {
		s1 += i;
	}
	queue<char> qu;
	bool t = false;
	for (int i = 0; i <= s1.length(); i++) {
		if (s1[i] - '0' == t) {
			qu.push(s1[i]);
		}
		else {
			cout << " " << qu.size();
			while (!qu.empty()) {
				qu.pop();
			}
			qu.push(s1[i]);
			t = !t;
		}
	}

	return 0;
}