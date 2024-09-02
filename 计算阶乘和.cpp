#include<iostream>
using namespace std;
int jicheng(int n);
int main(){
	int n , sum = 0;
	cin >> n;
	for(int i=1;i<=n;i++){
		sum+=jicheng(i);
	}
	cout << sum ;
	return 0;
}
int jicheng(int n){
	if(n==1){
		return 1;
	}else return  n*jicheng(n-1);
}
