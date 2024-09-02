#include<iostream>
using namespace std;
int main(){
	int n,sum=1 ,t=2;
	cin>>n;
	for(int i=1;i<=n;i++){
		sum *= t;
	}
	cout<< "2^" << n << " = " << sum;
	return 0;
}
