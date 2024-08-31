#include<iostream>
#include<string>
using namespace std;
int main4() {
	int i=0,t=0,n, m,t1,t2,making=0;
	string s[30];
	cin >> n;
	making = n;
	getchar();
	cin >> m;
	getchar();
	while (n--) {
		getline(cin, s[i]);
		i++;
	}

	while (1) {
		t1 = (int)s[t].find("qiandao");
		t2 = (int)s[t].find("easy");
		if (!(t1 != -1 || t2 != -1)) {
			m--;
			if (m < 0) {
				cout << s[t];
				break;
			}
		
		}
		t++;

		if (t == making) break;
	}
	if (m >= 0) {
		cout << "Wo AK le";
	}
	return 0;
}