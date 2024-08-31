#include<bits/stdc++.h>
using namespace std;
#define max 100500

int a[max] ;
int main2() {
	
	
	int n;
	cin >> n;
	int right = 0, left = 0;
	for (int i = 0; i <= n; i++) {
		cin >> left;
		a[abs(left - right)] = true;
		right = left;
	 }
	for (int i = 1; i < n; i++) {
		if (a[i] != true) {
			cout << "Not jolly" << endl;
			return 0;
		}
	}
	

	cout << "jolly"<<endl;
	return 0;
}