#include<iostream>
#include<conio.h>
#include<string>
#include<cstdio>
using namespace std;
#define max 1000
string H = " xiaogan";
string H1 = "123456";
typedef struct student {
	string  name;//名字
	string numble;//学号
	int sex;    //性别  1男  2女
	string  a;  //身份证
	string phone;   //电话  
	string home;//住址
}stu;
struct addressbooks {
	stu student[max];
	int sum = 0;//记录当前通讯录人数
};
int  exist(addressbooks* abs, string name) {
	for (int i = 0; i < abs->sum; i++) {
		if (abs->student[i].name == name || abs->student[i].numble == name) {
			return i;
		}
	}
	return -1;
}
void addstudent(addressbooks* abs) {
	if (abs->sum == max) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		string  name, numble, phone, home, a;
		int sex, t = 0;
		cout << "请输入名字" << endl;
		cin >> name;
		t = exist(abs, name);
		if (t == -1) {
			abs->student[abs->sum].name = name;
			cout << "请输入学号" << endl;
			cin >> numble;
			abs->student[abs->sum].numble = numble;
			cout << "请输入性别" << endl;
			cout << " 1 ：  男    ，  2：    女   " << endl;
			while (1) {
				cin >> sex;
				if (sex == 1 || sex == 2) {
					abs->student[abs->sum].sex = sex;
					break;
				}
				else cout << "输入有误，重新输入" << endl;
			}
			cout << "请输入身份证" << endl;
			cin >> a;
			abs->student[abs->sum].a = a;

			cout << "请输入电话" << endl;
			cin >> phone;
			abs->student[abs->sum].phone = phone;

			cout << "请输入住址" << endl;
			cin >> home;
			abs->student[abs->sum].home = home;

			abs->sum++;
			cout << "添加成功" << endl;
			system("pause");
			system("cls");//清屏操作
		}
		else {
			cout << "信息已存在" << endl;
			system("pause");
			system("cls");
		}
	}
}
void showstudent(addressbooks* abs) {
	if (abs->sum == 0) {
		cout << "此时通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->sum; i++) {
			cout << "名字:  " << abs->student[i].name << "\t";
			cout << "学号:  " << abs->student[i].numble << "\t";
			cout << "性别:  " << (abs->student[i].sex == 1 ? "男" : "女") << "\t";
			cout << "身份证:  " << abs->student[i].a << "\t";
			cout << "电话:  " << abs->student[i].phone << "\t";
			cout << "住址:  " << abs->student[i].home << endl;
		}
	}
	system("pause");
	system("cls");
}
void  modify(addressbooks* abs) {
	cout << "请输入要修改的联系人名字或者学号" << endl;
	string name;
	cin >> name;
	int t;
	t = exist(abs, name);
	if (t != -1) {
		string  name1, numble, phone, home, a;
		int sex;
		cout << "请输入名字" << endl;
		cin >> name1;
		abs->student[t].name = name1;
		cout << "请输入学号" << endl;
		cin >> numble;
		abs->student[t].numble = numble;
		cout << "请输入性别" << endl;
		cout << " 1 ：  男    ，  2：    女   " << endl;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->student[t].sex = sex;
				break;
			}
			else cout << "输入有误，重新输入" << endl;
		}
		cout << "请输入身份证" << endl;
		cin >> a;
		abs->student[t].a = a;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->student[t].phone = phone;
		cout << "请输入住址" << endl;
		cin >> home;
		abs->student[t].home = home;
		cout << "修改成功" << endl;
		system("pause");
		system("cls");//清屏操作
	}
	else {
		cout << "查无此人" << endl;
		system("puase");
		system("cls");
	}
}
void clean(addressbooks* abs) {
	cout << "是否要清空，是输入： 1   ，否输入： 2   。" << endl;
	int t;
	cin >> t;
	while (1) {
		if (t == 1) {
			cout << "已清空通讯录" << endl;
			abs->sum = 0;
			break;
		}
		else {
			cout << "输入有误，重新输入" << endl;
			cin >> t;
		}
	}
	system("pause");
	system("cls");
}
void Showmenu1() {
	cout << "1:   管理员登录" << endl;
	cout << "2:   学生登录" << endl;
	cout << "0:   退出登录" << endl;
}
int examine() {
	string s;
	string s1;
	char key;
	int i=0;
	cout << "用户名： ";
	cin >> s;
	getchar();
	cout << "密码： ";
	while ((key = _getch()) != '\r') {
		s1[i++] = key;
		putchar('*');
	}
	if (s == H && s1 == H1) {
		return 1;
	}
	return 0;
	
}
void Showmenu() {
	cout << " 1 添加学生信息" << endl;
	cout << " 2 显示学生信息" << endl;
	cout << " 3 删除学生信息" << endl;
	cout << " 4 修改学生信息" << endl;
	cout << " 5 清空学生信息" << endl;
	cout << " 0 退出通讯录" << endl;
}
void setwindow() {
	system(" title  账号登录");
	system("color f0");
}
int main() {
	addressbooks abs;
	abs.sum = 0;
	setwindow();
	while (1) {
		int t;
		Showmenu1();
		cin >> t;
		switch (t) {
		case 1:
		{    system("cls");
			int n=0;
			while (1) {
				n = examine();
				if (n == 1) {
					cout << "登录成功" << endl;
					system("pause");
					break;
				}
				else {
					cout << "账号或密码有误" << endl;
					system("pause");
					system("cls");
				}
			}
			system("cls");
			while (1) {
				int k;
				int making = 0;
				Showmenu();
				cin >> k;
				switch (k)
				{

				case 1://添加

					addstudent(&abs);
					break;
				case 2://显示
					showstudent(&abs);
					break;
				case 3://删除
				{	string  s;
				cout << "请输入名字或者学号" << endl;
				cin >> s;
				int other;
				if (exist(&abs, s) != -1) {
					other = exist(&abs, s);
					for (int i = other; i < abs.sum - 1; i++) {
						abs.student[i] = abs.student[i + 1];
					}
					abs.sum--;
					system("pause");
					system("cls");
				}
				else {
					cout << "查无此人" << endl;
					system("pause");
					system("cls");
				}
				}
				break;

				case 4://修改
					modify(&abs);
					break;
				case 5://清空
					clean(&abs);
					break;
				case 0:   cout << "欢迎下次再用" << endl;
					system("pause");
					making = 1;
					break;
				default:
					cout << "没有此选项，重新输入" << endl;
					system("puase");
					break;
				}
				if (making == 1) {
					system("cls");
					break;
				}
			}
			break;
		}
		case 2: {
			{
				int k;
				string name;
				cout << "请输入名字或者学号" << endl;
				cin >> name;
				if (exist(&abs, name) != -1) {
					k = exist(&abs, name);
					cout << "名字:  " << abs.student[k].name << "\t";
					cout << "学号:  " << abs.student[k].numble << "\t";
					cout << "性别:  " << (abs.student[k].sex == 1 ? "男" : "女") << "\t";
					cout << "身份证:  " << abs.student[k].a << "\t";
					cout << "电话:  " << abs.student[k].phone << "\t";
					cout << "住址:  " << abs.student[k].home << endl;
				}
				else cout << "查无此人" << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 0:
			cout << "谢谢使用" << endl;
			system("pause");
			break;
		default:
			cout << "输入有误，重新输入" << endl;
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;

}
