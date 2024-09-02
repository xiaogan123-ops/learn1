#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

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

void Showmenu1() {
	cout << "1: 管理员登录" << endl;
	cout << "2: 学生登录" << endl;
	cout << "0: 退出登录" << endl;
}

void Showmenu() {
	cout << "1 添加学生信息" << endl;
	cout << "2 显示学生信息" << endl;
	cout << "3 删除学生信息" << endl;
	cout << "4 查找学生信息" << endl;
	cout << "5 修改学生信息" << endl;
	cout << "0 退出通讯录" << endl;
}

stu* loadStudents() {
	stu* head = NULL;
	FILE* pf = fopen("text.txt", "r");
	if (pf == NULL) {
		cout << "无法打开文件" << endl;
		return NULL;
	}
	
	char name[20], numble[20], a[20], phone[20], home[20], sex[20];
	while (fscanf(pf, "%s %s %s %s %s %s", name, numble, sex, a, phone, home) == 6) {
		stu* pr = (stu*)malloc(sizeof(stu));
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
		pr->next = head;
		head = pr;
	}
	fclose(pf);
	return head;
}

void addStudent(stu** head) {
	stu* pr = new stu; // 使用 new 关键字分配内存
	if (pr == NULL) {
		cout << "内存分配失败" << endl;
		return;
	}
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

int main() {
	stu* head = NULL;
	head = loadStudents();
	while (1) {
		int t;
		Showmenu1();
		cin >> t;
		switch (t) {
		case 1:
{
	system("cls");
	Showmenu();
	int k;
	int making = 0;
	while (1) {
		cin >> k;
		switch (k) {
		case 1:
			addStudent(&head);
			break;
		case 2:
			Display(head);
			break;
		case 3:
			// 删除学生信息
			break;
		case 4:
			// 查找学生信息
			break;
		case 5:
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
}
			break;
		case 2:
			// 学生登录
			break;
		case 0:
			cout << "欢迎下次再用" << endl;
			break;
		default:
			cout << "没有此选项，重新输入" << endl;
			break;
		}
	}
	return 0;
}
