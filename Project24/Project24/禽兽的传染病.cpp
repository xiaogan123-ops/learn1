#include<bits/stdc++.h>
using namespace std;
long sum1 = 1;
int main6() {
	long m,n;
	cin>>m >> n;
	while (n--) {
		sum1+= sum1 * m;
	}
	cout << sum1;
	return 0;
}