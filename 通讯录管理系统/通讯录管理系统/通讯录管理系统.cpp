#include<iostream>
#include<conio.h>
#include<string>
#include<cstdio>
using namespace std;
#define max 1000
string H = " xiaogan";
string H1 = "123456";
typedef struct student {
	string  name;//����
	string numble;//ѧ��
	int sex;    //�Ա�  1��  2Ů
	string  a;  //���֤
	string phone;   //�绰  
	string home;//סַ
}stu;
struct addressbooks {
	stu student[max];
	int sum = 0;//��¼��ǰͨѶ¼����
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
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		string  name, numble, phone, home, a;
		int sex, t = 0;
		cout << "����������" << endl;
		cin >> name;
		t = exist(abs, name);
		if (t == -1) {
			abs->student[abs->sum].name = name;
			cout << "������ѧ��" << endl;
			cin >> numble;
			abs->student[abs->sum].numble = numble;
			cout << "�������Ա�" << endl;
			cout << " 1 ��  ��    ��  2��    Ů   " << endl;
			while (1) {
				cin >> sex;
				if (sex == 1 || sex == 2) {
					abs->student[abs->sum].sex = sex;
					break;
				}
				else cout << "����������������" << endl;
			}
			cout << "���������֤" << endl;
			cin >> a;
			abs->student[abs->sum].a = a;

			cout << "������绰" << endl;
			cin >> phone;
			abs->student[abs->sum].phone = phone;

			cout << "������סַ" << endl;
			cin >> home;
			abs->student[abs->sum].home = home;

			abs->sum++;
			cout << "��ӳɹ�" << endl;
			system("pause");
			system("cls");//��������
		}
		else {
			cout << "��Ϣ�Ѵ���" << endl;
			system("pause");
			system("cls");
		}
	}
}
void showstudent(addressbooks* abs) {
	if (abs->sum == 0) {
		cout << "��ʱͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->sum; i++) {
			cout << "����:  " << abs->student[i].name << "\t";
			cout << "ѧ��:  " << abs->student[i].numble << "\t";
			cout << "�Ա�:  " << (abs->student[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "���֤:  " << abs->student[i].a << "\t";
			cout << "�绰:  " << abs->student[i].phone << "\t";
			cout << "סַ:  " << abs->student[i].home << endl;
		}
	}
	system("pause");
	system("cls");
}
void  modify(addressbooks* abs) {
	cout << "������Ҫ�޸ĵ���ϵ�����ֻ���ѧ��" << endl;
	string name;
	cin >> name;
	int t;
	t = exist(abs, name);
	if (t != -1) {
		string  name1, numble, phone, home, a;
		int sex;
		cout << "����������" << endl;
		cin >> name1;
		abs->student[t].name = name1;
		cout << "������ѧ��" << endl;
		cin >> numble;
		abs->student[t].numble = numble;
		cout << "�������Ա�" << endl;
		cout << " 1 ��  ��    ��  2��    Ů   " << endl;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->student[t].sex = sex;
				break;
			}
			else cout << "����������������" << endl;
		}
		cout << "���������֤" << endl;
		cin >> a;
		abs->student[t].a = a;
		cout << "������绰" << endl;
		cin >> phone;
		abs->student[t].phone = phone;
		cout << "������סַ" << endl;
		cin >> home;
		abs->student[t].home = home;
		cout << "�޸ĳɹ�" << endl;
		system("pause");
		system("cls");//��������
	}
	else {
		cout << "���޴���" << endl;
		system("puase");
		system("cls");
	}
}
void clean(addressbooks* abs) {
	cout << "�Ƿ�Ҫ��գ������룺 1   �������룺 2   ��" << endl;
	int t;
	cin >> t;
	while (1) {
		if (t == 1) {
			cout << "�����ͨѶ¼" << endl;
			abs->sum = 0;
			break;
		}
		else {
			cout << "����������������" << endl;
			cin >> t;
		}
	}
	system("pause");
	system("cls");
}
void Showmenu1() {
	cout << "1:   ����Ա��¼" << endl;
	cout << "2:   ѧ����¼" << endl;
	cout << "0:   �˳���¼" << endl;
}
int examine() {
	string s;
	string s1;
	char key;
	int i=0;
	cout << "�û����� ";
	cin >> s;
	getchar();
	cout << "���룺 ";
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
	cout << " 1 ���ѧ����Ϣ" << endl;
	cout << " 2 ��ʾѧ����Ϣ" << endl;
	cout << " 3 ɾ��ѧ����Ϣ" << endl;
	cout << " 4 �޸�ѧ����Ϣ" << endl;
	cout << " 5 ���ѧ����Ϣ" << endl;
	cout << " 0 �˳�ͨѶ¼" << endl;
}
void setwindow() {
	system(" title  �˺ŵ�¼");
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
					cout << "��¼�ɹ�" << endl;
					system("pause");
					break;
				}
				else {
					cout << "�˺Ż���������" << endl;
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

				case 1://���

					addstudent(&abs);
					break;
				case 2://��ʾ
					showstudent(&abs);
					break;
				case 3://ɾ��
				{	string  s;
				cout << "���������ֻ���ѧ��" << endl;
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
					cout << "���޴���" << endl;
					system("pause");
					system("cls");
				}
				}
				break;

				case 4://�޸�
					modify(&abs);
					break;
				case 5://���
					clean(&abs);
					break;
				case 0:   cout << "��ӭ�´�����" << endl;
					system("pause");
					making = 1;
					break;
				default:
					cout << "û�д�ѡ���������" << endl;
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
				cout << "���������ֻ���ѧ��" << endl;
				cin >> name;
				if (exist(&abs, name) != -1) {
					k = exist(&abs, name);
					cout << "����:  " << abs.student[k].name << "\t";
					cout << "ѧ��:  " << abs.student[k].numble << "\t";
					cout << "�Ա�:  " << (abs.student[k].sex == 1 ? "��" : "Ů") << "\t";
					cout << "���֤:  " << abs.student[k].a << "\t";
					cout << "�绰:  " << abs.student[k].phone << "\t";
					cout << "סַ:  " << abs.student[k].home << endl;
				}
				else cout << "���޴���" << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 0:
			cout << "ллʹ��" << endl;
			system("pause");
			break;
		default:
			cout << "����������������" << endl;
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;

}