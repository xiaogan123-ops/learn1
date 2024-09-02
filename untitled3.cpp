#include<iostream>
using namespace std;
int main(){
	int n,m,sum=0;
	int a[3];
	cin>>n>>m;
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	if(n>m){
		for(int i=0;i<3;i++){
			if(a[i]==0){
				sum++;
			}
		}
		if(sum!=0){
			cout<<"The winner is a: "<<n<<" + "<<sum;
		}else  cout<<"The winner is b: "<<m<<" + "<<3;

	}else{
		for(int i=0;i<3;i++){
			if(a[i]==1){
				sum++;
			}
		}
		if(sum!=0){
			cout<<"The winner is b: "<<m<<" + "<<sum;
		}else  cout<<"The winner is a: "<<n<<" + "<<3;
	}
}
