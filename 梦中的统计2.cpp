#include<iostream>
using namespace std;
int main() {
	int m, n, i, j,a[10] = {0};
	cin >> m >> n;
	for (i = m; i <= n; i++) {
		j=i;
	while(j>0){
		a[j%10]++;
		j=j/10;
	}
	}
	for (i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
