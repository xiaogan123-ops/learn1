#include<iostream>
#include<string>
using namespace std;
const string s1 = "chi1 huo3 guo1";
bool Bool(string s){
	if ((int)s.find(s1)!=-1) {
		
		return 1;
	}
	else return 0;
}
int main2() {
	int t=0;
	string s[1000];
	int i = 0,total=0;
	while (1) {
		getline(cin, s[i]);
		if (s[i] == ".") break;
	
		i++;
	}
	
	for (int j = i - 1; j >= 0; j--) {
		if (Bool(s[j])) {
			t = j + 1;
			total++;
		}
	}
	cout << i << endl;
	if (total !=0) {
		cout << t << " " << total;
	}
	else cout << "-_-#";
		return 0;
}