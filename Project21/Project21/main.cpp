#include<iostream>
#undef UNICODE
#include <conio.h>
#include<stdio.h>
#include<graphics.h> //����ͼ�ο�ͷ�ļ�
#include<mmsyscom.h>//������ý���ͷ�ļ�
#include<string>
#include<fstream>
using namespace std;
IMAGE m_bk;
typedef struct Student {
	string numble;//ѧ��
	string name;//����
	string sex;//�Ա�
	string phone;//�绰
	string a;//���֤
	string  home;//��ͥ��ַ
	struct Student* next;
}stu;
stu* head = NULL;
unsigned int count;
void loadStudents(stu** head) {
	ifstream file("abc.txt");
	if (!file.is_open()) {
		std::cout << "�޷����ļ�" << std::endl;
		return;
	}

	string name, numble, sex, a, phone, home;


	while (file >> name >> numble >> sex >> a >> phone >> home) {
		bool duplicate = false;
		stu* current = *head;
		while (current != NULL) {
			if (current->name == name || current->numble == numble) {
				duplicate = true;
				break;
			}
			current = current->next;
		}

		if (duplicate) {
			cout << "�ظ���ѧ����Ϣ��" << name << " " << numble << endl;
			continue; //�����ظ���ѧ����Ϣ
		}


		stu* pr = new stu;
		if (pr == nullptr) {
			cout << "�ڴ����ʧ��" << endl;
			file.close();
			exit(1);
		}

		pr->name = name;
		pr->numble = numble;
		pr->sex = sex;
		pr->a = a;
		pr->phone = phone;
		pr->home = home;
		pr->next = nullptr;

		if (*head == NULL) {
			*head = pr;
		}
		else {
			stu* temp = *head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = pr;
		}
	}

	file.close();
}

//ͼ��
void nodoLine() {
	// ���ñ���ߵ���ɫ����ʽ
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);

	// ������Ŀ�Ⱥ͸߶�
	int Width = 100; // ��Ԫ����
	int Height = 25; // ��Ԫ��߶�
	int a = 14; // ����
	int b = 6; // ����
	int h = 20; // ˮƽ���
	int v = 10; // ��ֱ���
	int tableWidth = b * Width + (b + 1) * h; // �����740
	int tableHeight = a * Height + (a + 1) * v; // ���߶�500

	// ���������Ͻ�λ��
	int tableX = 100;
	int tableY = 100;

	// ����ˮƽ��
	for (int i = 0; i <= a; ++i) {
		line(tableX, tableY + (Height + v) * i, tableX + tableWidth, tableY + (Height + v) * i);
	}

	// ���ƴ�ֱ��
	for (int i = 0; i <= b; ++i) {
		line(tableX + (Width + h) * i, tableY, tableX + (Width + h) * i, tableY + tableHeight);
	}

	// �����ı���ɫ
	settextcolor(RED);

	// �����ı�λ��
	int textX[] = { tableX + h, tableX + Width + 2 * h,
					tableX + 2 * Width + 3 * h, tableX + 3 * Width + 4 * h,
					tableX + 4 * Width + 5 * h, tableX + 5 * Width + 6 * h };
	string text[] = { "ѧ��", "����", "�Ա�", "�绰", "���֤", "��ͥ��ַ" };
	for (int i = 0; i < b; ++i) {
		outtextxy(textX[i], tableY - 20, text[i].c_str()); // �����ı��Ĵ�ֱλ��
	}

	// �ָ��ı���ɫ
	settextcolor(BLACK);
}


//��ʾѧ����Ϣ
void Display(stu* head) {
	if (head == NULL) {
		outtextxy(440, 600, "û����Ϣ");
		return;
	}
	nodoLine(); // ���Ʊ��
	int row = 0;
	settextstyle(25, 0, "����");
	while (head != NULL) {
		// ����ÿ��ѧ����Ϣ����ʾλ�ã�ʹ���Ӧ������һ����Ԫ����
		int x = 150; // ��һ�е� x ����
		int y = 110 + row * 35; // ÿ�е� y ����
		outtextxy(x, y, head->numble.c_str());
		x += 130; // ��֮��ļ��Ϊ 150
		outtextxy(x, y, head->name.c_str());
		x += 130;
		outtextxy(x, y, head->sex.c_str());
		x += 120;
		outtextxy(x, y, head->phone.c_str());
		x += 110;
		outtextxy(x, y, head->a.c_str());
		x += 110;
		outtextxy(x, y, head->home.c_str());
		head = head->next;
		row++;
	}
}



//���ѧ����Ϣ
void addStudent(stu** head) {
	// ��ȡ�û������ѧ����Ϣ
	char numble[20], name[20], sex[4], phone[20], a[20], home[20];
	InputBox(numble, 20, "��������Ҫ���ѧ�����ֻ�ѧ��");
	// �ж�ѧ����Ϣ�Ƿ��ظ�
	stu* pr1 = *head;
	while (pr1 != NULL) {
		if (pr1->name == numble || pr1->numble == numble) {
			settextstyle(20, 0, "����");
			outtextxy(300, 500, "�Ѵ���");
			return;
		}
		pr1 = pr1->next;
	}
	settextstyle(20, 0, "����");
	outtextxy(300, 400, "��ϲͨ��,���������");

	InputBox(name, 20, "��������Ҫ���ѧ������");
	InputBox(sex, 4, "��������Ҫ���ѧ���Ա�");
	InputBox(phone, 20, "��������Ҫ���ѧ���ֻ���");
	InputBox(a, 20, "��������Ҫ���ѧ�����֤");
	InputBox(home, 20, "��������Ҫ���ѧ������ѧԺ");

	// �����½ڵ㲢��ֵ
	stu* pr = new stu;
	if (pr == NULL) {
		cout << "�ڴ����ʧ��" << endl;
		return;
	}
	pr->name = name;
	pr->numble = numble;
	pr->sex = sex;
	pr->a = a;
	pr->phone = phone;
	pr->home = home;
	pr->next = NULL;

	// ���½ڵ���ӵ�����ͷ��
	if (*head == NULL) {
		*head = pr;
	}
	else {
		pr->next = *head;
		*head = pr;
	}

	// ���½�����ʾ����ӵ�ѧ����Ϣ
	putimage(0, 0, &m_bk);
	loadimage(&m_bk, "./images/abc.jpg", ::getwidth(), ::getheight());
	Display(*head); // ��ʾ����ӵ�ѧ����Ϣ
}//��������

//�޸�ѧ����Ϣ
void modifyStudent(stu* head) {
	char s[20], ss[2];
	char numble[20], name[20], sex[4], phone[20], a[20], home[20];
	stu* p;
	p = head;
	InputBox(s, 20, "��������Ҫ����ѧ����������ѧ��");
	bool finded = false;
	while (p != NULL) {
		if (p->name == s || p->numble == s) {
			finded = true;
			nodoLine();
			int x = 150; // ��һ�е� x ����
			int y = 110; // ÿ�е� y ����
			outtextxy(x, y, head->numble.c_str());
			x += 130; // ��֮��ļ��Ϊ 150
			outtextxy(x, y, head->name.c_str());
			x += 130;
			outtextxy(x, y, head->sex.c_str());
			x += 120;
			outtextxy(x, y, head->phone.c_str());
			x += 110;
			outtextxy(x, y, head->a.c_str());
			x += 110;
			outtextxy(x, y, head->home.c_str());
			InputBox(ss, 2, "��������Ҫ�޸ĵ���Ϣ(1.ѧ�� 2.���� 3.�Ա� 4.�绰 5.���֤ 6.סַ)");
			switch (ss[0]) {
			case '1':
				InputBox(numble, 20, "�������޸ĺ��ѧ��");
				p->numble = numble;
				break;
			case '2':
				InputBox(name, 20, "�������޸ĺ������");
				p->name = name;
				break;
			case '3':
				InputBox(sex, 20, "�������޸ĺ���Ա�");
				p->sex = sex;
				break;
			case '4':
				InputBox(phone, 20, "�������޸ĺ�ĵ绰");
				p->phone = phone;
				break;
			case '5':
				InputBox(a, 20, "�������޸ĺ�����֤");
				p->a = a;
				break;
			case 6:
				InputBox(home, 20, "�������޸�סַ");
				p->home = home;
				break;
			}
			break;
		}
		p = p->next;
	}
	settextstyle(25, 0, "����");
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	char arr[] = "�ѳɹ��޸ĸ�ѧ������Ϣ";
	outtextxy(440, 600, arr);
	if (!finded) {
		settextstyle(25, 0, "����");
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		char arr[] = "û�в�ѯ����ͬѧ����Ϣ";
		outtextxy(440, 600, arr);
	}

}


//ɾ��ѧ����Ϣ
void deleteStudent(stu** head) {
	char keyword[20];
	InputBox(keyword, 20, "������Ҫɾ����ѧ��������ѧ�ţ�");

	stu* pr = *head;
	stu* pr1 = NULL;

	while (pr != NULL) {
		if (pr->name == keyword || pr->numble == keyword) {
			if (pr1 != NULL) {
				pr1->next = pr->next;
			}
			else {
				*head = pr->next;
			}
			free(pr); // �ͷű�ɾ���ڵ���ڴ�ռ�
			settextstyle(30, 0, "����");
			outtextxy(400, 400, "ɾ���ɹ�");

			return;
		}
		pr1 = pr;
		pr = pr->next;
	}
	outtextxy(300, 400, "û���ҵ���ѧ����Ϣ");
}


//����ѧ��
void searchstudent(stu* head) {
	char s[20];
	InputBox(s, 20, "������Ҫ���ҵ�ѧ��������ѧ�ţ�");

	while (head != NULL) {       //�ַ���ȡ����substr
		if (head->numble == s || head->name == s) {
			settextstyle(20, 0, "����");
			outtextxy(10, 110, "���ҳɹ�");
			nodoLine(); // ���Ʊ��
			int x = 150; // ��һ�е� x ����
			int y = 110; // ÿ�е� y ����
			outtextxy(x, y, head->numble.c_str());
			x += 130; // ��֮��ļ��Ϊ 150
			outtextxy(x, y, head->name.c_str());
			x += 130;
			outtextxy(x, y, head->sex.c_str());
			x += 120;
			outtextxy(x, y, head->phone.c_str());
			x += 110;
			outtextxy(x, y, head->a.c_str());
			x += 110;
			outtextxy(x, y, head->home.c_str());
			head = head->next;
			return;
		}
		head = head->next;
	}
	settextstyle(30, 0, "����");
	outtextxy(400, 400, "û�и�����Ϣ");
}

void recordStudent(stu* head) {

	string s = "ab.txt";//��һ��д�ļ���
	fstream fout(s, ios::out | ios::app);
	//iOS����out���ļ�����д����
	//iOS����app ���ļ�Ϊ׷�ӷ�ʽд�ļ�
	if (fout.fail()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	while (head != NULL) {
		fout << head->name << " " << head->numble << " " << head->sex << " " << head->a << " " << head->phone << " " << head->home << endl;
		head = head->next;
	}
	fout.close();
}
//�ļ���¼ѧ����Ϣ
void drawMenuItem(int x1, int y1, int x2, int y2, const char* text) {
	setfillcolor(BLUE);
	fillrectangle(x1, y1, x2, y2);
	settextstyle(15, 0, "΢�����");
	setbkmode(TRANSPARENT);
	outtextxy((x1 + x2) / 2 - 30, (y1 + y2) / 2 - 5, text);
}
int currentPage = 0;
void table() {
	
	drawMenuItem(300, 600, 420, 620, "��һҳ");
	drawMenuItem(500, 600, 620, 620, "��һҳ");
	MOUSEMSG n;
	n = GetMouseMsg();
	if (n.x >= 300 && n.x <= 420 && n.y >= 600 && n.y <= 620) {
		setlinecolor(RED);
		rectangle(298, 598, 422, 622);
		if (n.uMsg == WM_LBUTTONDOWN) {
			// �������������ʵ����Ӧ����.
			if (currentPage > 0) {
				currentPage--; // �л�����һҳ
				cleardevice(); // �����Ļ
				Display(head); // ��ʾ��һҳ��ѧ����Ϣ
			}
		}
	}
	else if (n.x >= 500 && n.x <= 620 && n.y >= 600 && n.y <= 620) {
		setlinecolor(RED);
		rectangle(498, 598, 622, 622);
		if (n.uMsg == WM_LBUTTONDOWN) {
			// �������������ʵ����Ӧ����.
			// ע�⣺������Ҫ����߼���ȷ�����ᳬ�����ҳ������
			currentPage++; // �л�����һҳ
			cleardevice(); // �����Ļ
			Display(head); // ��ʾ��һҳ��ѧ����Ϣ
		}
	}
	else {
		setlinecolor(WHITE);
		rectangle(298, 598, 422, 622);
		rectangle(498, 598, 622, 622);
	}
}

void showmenu() {//��ҳ�溯��
	string title = "ͨѶ¼����ϵͳ";
	int m_w = 940, m_h = 640;
	initgraph(m_w, m_h, EX_SHOWCONSOLE);
	HWND hwnd = initgraph(m_w, m_h); // Get the window handle
	SetWindowText(hwnd, title.c_str());


	loadimage(&m_bk, "./images/abc.jpg", m_w, m_h);
	putimage(0, 0, &m_bk);

	drawMenuItem(370, 200, 570, 250, "��ʾѧ��");
	drawMenuItem(370, 255, 570, 305, "���ѧ��");
	drawMenuItem(370, 310, 570, 360, "ɾ��ѧ��");
	drawMenuItem(370, 365, 570, 415, "�޸�ѧ��");
	drawMenuItem(370, 420, 570, 470, "����ѧ��");
	drawMenuItem(370, 475, 570, 525, "�˳�ϵͳ");
	while (1) {
		MOUSEMSG m;
		m = GetMouseMsg();
		//��ʾ
		if (m.x >= 370 && m.x <= 570 && m.y >= 200 && m.y <= 250) {
			setlinecolor(RED);
			rectangle(368, 198, 572, 252);
			if (m.uMsg == WM_LBUTTONDOWN) {	//�������������ʵ����Ӧ����.
				cleardevice();
				putimage(0, 0, &m_bk);
				loadimage(&m_bk, "./images/abc.jpg", ::getwidth(), ::getheight());
				
				Display(head);
				
					break;
				}
			}
		
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ����ɫ�߿�.
			setlinecolor(WHITE);
			rectangle(368, 198, 572, 252);
		}
		//���
		if (m.x >= 370 && m.x <= 570 && m.y >= 255 && m.y <= 305) {
			setlinecolor(RED);
			rectangle(368, 253, 572, 302);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				putimage(0, 0, &m_bk);
				loadimage(&m_bk, "./images/abc.jpg", ::getwidth(), ::getheight());
				addStudent(&head);
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ����ɫ�߿�.
			setlinecolor(WHITE);
			rectangle(368, 253, 572, 302);
		}
		//ɾ��ͨѶ¼
		if (m.x >= 370 && m.x <= 570 && m.y >= 310 && m.y <= 360) {
			setlinecolor(RED);
			rectangle(368, 312, 572, 362);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				putimage(0, 0, &m_bk);
				loadimage(&m_bk, "./images/abc.jpg", ::getwidth(), ::getheight());
				deleteStudent(&head);
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ����ɫ�߿�.
			setlinecolor(WHITE);
			rectangle(368, 312, 572, 362);
		}
		//�޸�ͨѶ¼
		if (m.x >= 370 && m.x <= 570 && m.y >= 365 && m.y <= 415) {
			setlinecolor(RED);
			rectangle(368, 367, 572, 417);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				putimage(0, 0, &m_bk);
				loadimage(&m_bk, "./images/abc.jpg", ::getwidth(), ::getheight());
				modifyStudent(head);
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ����ɫ�߿�.
			setlinecolor(WHITE);
			rectangle(368, 367, 572, 417);
		}
		//����
		if (m.x >= 370 && m.x <= 570 && m.y >= 420 && m.y <= 470) {
			setlinecolor(RED);
			rectangle(368, 422, 572, 472);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				putimage(0, 0, &m_bk);
				loadimage(&m_bk, "./images/abc.jpg", ::getwidth(), ::getheight());
				searchstudent(head);
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ����ɫ�߿�.
			setlinecolor(WHITE);
			rectangle(368, 422, 572, 472);
		}
		//�˳�
		if (m.x >= 370 && m.x <= 570 && m.y >= 475 && m.y <= 525) {
			setlinecolor(RED);
			rectangle(368, 477, 572, 527);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.

				return;
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ����ɫ�߿�.
			setlinecolor(WHITE);
			rectangle(368, 477, 572, 527);
		}
	}

}

ExMessage m_msg; // ��Ϣ
bool hasMsg() {
	return kbhit(); // ����а���������
}

ExMessage& getMsg() {
	static ExMessage msg;
	msg.message = WM_KEYDOWN; //esc����
	msg.vkcode = getch();
	return msg;
}
int main()
{
	loadStudents(&head);
	showmenu();
	while (true) {
		if (MouseHit()) {
			MOUSEMSG m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN) {
				if (m.x >= 370 && m.x <= 570 && m.y >= 475 && m.y <= 525) {
					recordStudent(head);
					closegraph();
					return 0; // Exit the program
				}
			}
		}
		//����а�������
		if (hasMsg()) {
			//��esc�˻���ҳ��
			switch (getMsg().vkcode) {
			case VK_ESCAPE:
				showmenu();
				break;

			default:
				break;
			}
		}
	}
	return 0;
}