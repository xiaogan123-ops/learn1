#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
const string making1="123456";
const string making2="abc123";
int main(){
	string s1,s2;
	int k=0;
	char key;
	cin>>s1;
	getchar();
	while((key=_getch())!='\r'){
         s2+=key;
	  putchar('*');
	}
	cout<<endl;
	if(s1==making1&&s2==making2){
		cout<<"登录成功"<<endl;
	}
	return 0;
}
