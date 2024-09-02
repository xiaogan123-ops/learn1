#include<iostream>
#include<string>
using namespace std;
int main() {
	int i=0,j,k;
	string s;
	getline(cin, s);

	while(i<s.length()) {
		if (s[i] != '6') {
			cout << s[i];
			i++;
		}
		else {
			j = i;
			while (s[j] == '6'&&s[j]!='\n') {
				j++;
			}
			if (j - i > 9) {
				cout << "27";
			}
			else if (j - i > 3) {
				cout << "9";
			}
			else {
				for (k=j;k>i ;k--) {//注意不能（；j>=i;j--）
					cout << "6";
				}
			}
			i = j;
		}
		
	  }
	return 0;
}
