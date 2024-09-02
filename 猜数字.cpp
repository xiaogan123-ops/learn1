#include<iostream>
#include<cmath>
using namespace std;
typedef struct  student{
	string name;
	int a;
}stu;
int main(){
	stu student[10000];
	int sum=0,n;
	double aver=0,min=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>student[i].name>>student[i].a;
		sum+=student[i].a;
	}
	aver=(double)(sum*1.0/n/2);
	min=abs(student[0].a-aver);
	for(int i=1;i<n;i++){
		if(abs(student[i].a-aver)<min){
			min=abs(student[i].a-aver);
		}
	}
	for(int i=0;i<n;i++){
		if(abs(student[i].a-aver)==min){
			cout<<round(aver)<<" "<<student[i].name;
		}
	}
	return 0;
	
}
