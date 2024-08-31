#include<iostream>
using namespace std;
int main3() {
	int i, a[24] = {0};
	int t;
	for (i = 0; i < 24; i++) {
		cin >> a[i];
	}
	while (1) {
		cin >> t;
		if (t < 0 || t>23) break;
		if (a[t] > 50) {
			cout << a[t] << " ";
			cout << "Yes";
		}
		else {
			cout << a[t] << " ";
			cout << "No";
		}
		cout << endl;
	}
	return 0;
}