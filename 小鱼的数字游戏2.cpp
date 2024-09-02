#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int i=0,sum=0;
	string a;
	getline(cin, a);
	for ( i = 0;i<a.size();i++) {
		if (a[i] == 'a' || a[i] == 'd' || a[i] == 'g' || a[i] == 'j' || a[i] == 'm' || a[i] == 'p' || a[i] == 't' || a[i] == 'w'||a[i]==' ') {
			sum += 1;
		}
		if (a[i] == 'b' || a[i] == 'e' || a[i] == 'h' || a[i] == 'k' || a[i] == 'n' || a[i] == 'q' || a[i] == 'u' || a[i] == 'x') {
			sum += 2;
		}
		if (a[i] == 'c' || a[i] == 'f' || a[i] == 'i' || a[i] == 'l' || a[i] == 'o' || a[i] == 'r' || a[i] == 'v' || a[i] == 'y') {
			sum += 3;
		}
		if(a[i]=='s'||a[i]=='z') {
			sum += 4;
		}
	}
	cout << sum;
	return 0;
}
