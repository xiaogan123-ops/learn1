#include<bits/stdc++.h>
using namespace std;
#include<stack>
int main6() {
	char c;
	stack<char> s;
	scanf_s("%c", &c);
	while (c!= '@') {
		if (c == '(') {
			s.push(c);
		}
		if (c == ')') {
			if (!s.empty()) {
				s.pop();
			}
			else { 
				
				cout << "NO"; 
				return 0;
			}
		}
		
		scanf_s("%c", &c);
	}
	if (!s.empty()) {
		cout << "NO";
	}else 
	cout << "YES";
	return 0;
}