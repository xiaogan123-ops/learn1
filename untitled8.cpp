#include <iostream>
#include <string>
#include <cstdio>
#include<fstream>
#include<conio.h>
using namespace std;
typedef struct student {
	string  name;   // 名字
	string numble;  // 学号
	string sex;     // 性别 1男 2女
	string  a;      // 身份证
	string phone;   // 电话
	string home;    // 住址
	struct student* next;
} stu;


void Showmenu() {
	cout << "1 键盘添加学生信息" << endl;
	cout << "2 文件添加学生信息" << endl;
	cout << "3 显示学生信息" << endl;
	cout << "4 删除学生信息" << endl;
	cout << "5 查找学生信息" << endl;
	cout << "6 修改学生信息" << endl;
	cout << "0 退出通讯录" << endl;
}

void loadStudents(stu** head) {
	FILE* pf = fopen("abc.txt", "r");
	if (pf == NULL) {
		cout << "无法打开文件" << endl;
		return;
	}
	
	char name[20], numble[20], a[20], phone[20], home[20], sex[20];
	while (fscanf(pf, "%s %s %s %s %s %s", name, numble, sex, a, phone, home) == 6) {
		stu* pr = new stu;;
		if (pr == NULL) {
			cout << "内存分配失败" << endl;
			fclose(pf);
			exit(1);
		}
		pr->name = name;
		pr->numble = numble;
		pr->sex = sex;
		pr->a = a;
		pr->phone = phone;
		pr->home = home;
		pr->next = NULL;
		if (head == NULL) {
			*head = pr;
		}
		else {
			pr->next = *head;
			*head = pr;
		}
	}
	fclose(pf);
	cout << "添加成功" << endl;
}

void addStudent(stu** head) {
	stu* pr1 = *head;
	stu* pr = new stu; // 使用 new 关键字分配内存
	if (pr == NULL) {
		cout << "内存分配失败" << endl;
		return;
	}
	
	cout << "请输入名字或学号" << endl;
	string s1;
	cin >> s1;
	while (pr1 != NULL) {
		if (pr1->name == s1 || pr1->numble == s1) {
			cout << "已经有该人信息" << endl;
			return;
		}
		pr1 = pr1->next;
	}
	cout << "恭喜通过,请继续输入" << endl;
	string name, numble, a, sex, phone, home;
	
	cout << "请输入名字" << endl;
	cin >> name;
	cout << "请输入学号" << endl;
	cin >> numble;
	cout << "请输入性别" << endl;
	cin >> sex;
	cout << "请输入身份证" << endl;
	cin >> a;
	cout << "请输入电话" << endl;
	cin >> phone;
	cout << "请输入住址" << endl;
	cin >> home;
	
	pr->name = name;
	pr->numble = numble;
	pr->sex = sex;
	pr->a = a;
	pr->phone = phone;
	pr->home = home;
	pr->next = NULL; // 将新节点的 next 指针设置为 NULL
	
	if (*head == NULL) { // 如果链表为空，将新节点设置为头节点
		*head = pr;
	}
	else {
		pr->next = *head; // 将新节点的 next 指针指向当前链表的头节点
		*head = pr; // 将新节点设置为新的头节点
	}
}


void Display(stu* head) {
	while (head != NULL) {
		cout << "名字：" << head->name << '\t';
		cout << "学号：" << head->numble << '\t';
		cout << "性别：" << head->sex << '\t';
		cout << "身份证：" << head->a << '\t';
		cout << "电话：" << head->phone << '\t';
		cout << "住址：" << head->home << endl;
		head = head->next;
	}
}

void modifyStudent(stu* head) {
	string s;
	cout << "请输入要修改的名字或学号" << endl;
	cin >> s;
	while (head != NULL) {
		if (head->name == s || head->numble == s) {
			cout << "请输入要修改的名字" << endl;
			cin >> head->name;
			cout << "请输入要修改的学号" << endl;
			cin >> head->numble;
			cout << "请输入要修改的性别" << endl;
			cin >> head->sex;
			cout << "请输入要修改的身份证" << endl;
			cin >> head->a;
			cout << "请输入要修改的电话" << endl;
			cin >> head->phone;
			cout << "请输入要修改的住址" << endl;
			cin >> head->home;
			return;
		}
		head = head->next;
	}
	cout << "没有该人" << endl;
}

void deleteStudent(stu** head) {
	cout << "请输入要删除的名字或学号" << endl;
	string s;
	cin >> s;
	stu* pr = NULL, * pr1 = *head;
	while (pr1 != NULL) {
		if (pr1->name == s || pr1->numble == s) {
			if (pr1->next != NULL) {
				pr->next = pr1->next;
				free(pr1);
				return;
			}
			else {
				pr->next = NULL;
				free(pr1);
				return;
			}
		}
		pr = pr1;
		pr1 = pr1->next;
	}
	cout << "没有该人" << endl;
}

void searchStudent(stu* head) {
	cout << "请输入要查询的名字或学号" << endl;
	string s;
	cin >> s;
	while (head != NULL) {
		if (head->name == s || head->numble == s) {
			cout << "名字：" << head->name << '\t';
			cout << "学号：" << head->numble << '\t';
			cout << "性别：" << head->sex << '\t';
			cout << "身份证：" << head->a << '\t';
			cout << "电话：" << head->phone << '\t';
			cout << "住址：" << head->home << endl;
			return;
		}
		head = head->next;
	}
	cout << "没有该人信息" << endl;
}

void recordStudent(stu* head) {
	
	string s = "ab.txt";
	fstream fout(s, ios::out | ios::app);
	if (fout.fail()) {
		cout << "文件打开失败" << endl;
		return;
	}
	while (head != NULL) {
		fout << head->name << " " << head->numble << " " << head->sex << " " << head->a << " " << head->phone << " " << head->home << endl;
		head = head->next;
	}
	fout.close();
}


int main() {
	
	stu* head = NULL;
	
	Showmenu();
	int k;
	int making = 0;
	while (1) {
		cin >> k;
		switch (k) {
			case 1://键盘添加
			addStudent(&head);
			break;
			case 2://文件添加
			loadStudents(&head);
			break;
		case 3:
			Display(head);
			break;
		case 4:
			// 删除学生信息
			deleteStudent(&head);
			break;
		case 5:
			// 查找学生信息
			searchStudent(head);
			break;
		case 6:
			modifyStudent(head);
			// 修改学生信息
			break;
		case 0:
			cout << "欢迎下次再用" << endl;
			making = 1;
			break;
		default:
			cout << "没有此选项，重新输入" << endl;
			break;
		}
		if (making == 1) {
			break;
		}
		system("pause");
		system("cls");
		Showmenu();
	}
	
	
	recordStudent(head);
	return 0;
}
