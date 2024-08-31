#include<iostream>
#undef UNICODE
#include <conio.h>
#include<stdio.h>
#include<graphics.h> //包含图形库头文件
#include<mmsyscom.h>//包含多媒体库头文件
#include<string>
#include<fstream>
using namespace std;
IMAGE m_bk;
typedef struct Student {
	string numble;//学号
	string name;//姓名
	string sex;//性别
	string phone;//电话
	string a;//身份证
	string  home;//家庭地址
	struct Student* next;
}stu;
stu* head = NULL;
unsigned int count;
void loadStudents(stu** head) {
	ifstream file("abc.txt");
	if (!file.is_open()) {
		std::cout << "无法打开文件" << std::endl;
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
			cout << "重复的学生信息：" << name << " " << numble << endl;
			continue; //跳过重复的学生信息
		}


		stu* pr = new stu;
		if (pr == nullptr) {
			cout << "内存分配失败" << endl;
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

//图表
void nodoLine() {
	// 设置表格线的颜色和样式
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);

	// 计算表格的宽度和高度
	int Width = 100; // 单元格宽度
	int Height = 25; // 单元格高度
	int a = 14; // 行数
	int b = 6; // 列数
	int h = 20; // 水平间距
	int v = 10; // 垂直间距
	int tableWidth = b * Width + (b + 1) * h; // 表格宽度740
	int tableHeight = a * Height + (a + 1) * v; // 表格高度500

	// 计算表格左上角位置
	int tableX = 100;
	int tableY = 100;

	// 绘制水平线
	for (int i = 0; i <= a; ++i) {
		line(tableX, tableY + (Height + v) * i, tableX + tableWidth, tableY + (Height + v) * i);
	}

	// 绘制垂直线
	for (int i = 0; i <= b; ++i) {
		line(tableX + (Width + h) * i, tableY, tableX + (Width + h) * i, tableY + tableHeight);
	}

	// 设置文本颜色
	settextcolor(RED);

	// 设置文本位置
	int textX[] = { tableX + h, tableX + Width + 2 * h,
					tableX + 2 * Width + 3 * h, tableX + 3 * Width + 4 * h,
					tableX + 4 * Width + 5 * h, tableX + 5 * Width + 6 * h };
	string text[] = { "学号", "姓名", "性别", "电话", "身份证", "家庭地址" };
	for (int i = 0; i < b; ++i) {
		outtextxy(textX[i], tableY - 20, text[i].c_str()); // 修正文本的垂直位置
	}

	// 恢复文本颜色
	settextcolor(BLACK);
}


//显示学生信息
void Display(stu* head) {
	if (head == NULL) {
		outtextxy(440, 600, "没有信息");
		return;
	}
	nodoLine(); // 绘制表格
	int row = 0;
	settextstyle(25, 0, "宋体");
	while (head != NULL) {
		// 计算每个学生信息的显示位置，使其对应到表格的一个单元格内
		int x = 150; // 第一列的 x 坐标
		int y = 110 + row * 35; // 每行的 y 坐标
		outtextxy(x, y, head->numble.c_str());
		x += 130; // 列之间的间隔为 150
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



//添加学生信息
void addStudent(stu** head) {
	// 读取用户输入的学生信息
	char numble[20], name[20], sex[4], phone[20], a[20], home[20];
	InputBox(numble, 20, "请输入需要添加学生名字或学号");
	// 判断学生信息是否重复
	stu* pr1 = *head;
	while (pr1 != NULL) {
		if (pr1->name == numble || pr1->numble == numble) {
			settextstyle(20, 0, "宋体");
			outtextxy(300, 500, "已存在");
			return;
		}
		pr1 = pr1->next;
	}
	settextstyle(20, 0, "宋体");
	outtextxy(300, 400, "恭喜通过,请继续输入");

	InputBox(name, 20, "请输入需要添加学生姓名");
	InputBox(sex, 4, "请输入需要添加学生性别");
	InputBox(phone, 20, "请输入需要添加学生手机号");
	InputBox(a, 20, "请输入需要添加学生身份证");
	InputBox(home, 20, "请输入需要添加学生所属学院");

	// 创建新节点并赋值
	stu* pr = new stu;
	if (pr == NULL) {
		cout << "内存分配失败" << endl;
		return;
	}
	pr->name = name;
	pr->numble = numble;
	pr->sex = sex;
	pr->a = a;
	pr->phone = phone;
	pr->home = home;
	pr->next = NULL;

	// 将新节点添加到链表头部
	if (*head == NULL) {
		*head = pr;
	}
	else {
		pr->next = *head;
		*head = pr;
	}

	// 更新界面显示新添加的学生信息
	putimage(0, 0, &m_bk);
	loadimage(&m_bk, "./images/abc.jpg", ::getwidth(), ::getheight());
	Display(*head); // 显示新添加的学生信息
}//键盘输入

//修改学生信息
void modifyStudent(stu* head) {
	char s[20], ss[2];
	char numble[20], name[20], sex[4], phone[20], a[20], home[20];
	stu* p;
	p = head;
	InputBox(s, 20, "请输入需要查找学生的姓名或学号");
	bool finded = false;
	while (p != NULL) {
		if (p->name == s || p->numble == s) {
			finded = true;
			nodoLine();
			int x = 150; // 第一列的 x 坐标
			int y = 110; // 每行的 y 坐标
			outtextxy(x, y, head->numble.c_str());
			x += 130; // 列之间的间隔为 150
			outtextxy(x, y, head->name.c_str());
			x += 130;
			outtextxy(x, y, head->sex.c_str());
			x += 120;
			outtextxy(x, y, head->phone.c_str());
			x += 110;
			outtextxy(x, y, head->a.c_str());
			x += 110;
			outtextxy(x, y, head->home.c_str());
			InputBox(ss, 2, "请输入需要修改的信息(1.学号 2.姓名 3.性别 4.电话 5.身份证 6.住址)");
			switch (ss[0]) {
			case '1':
				InputBox(numble, 20, "请输入修改后的学号");
				p->numble = numble;
				break;
			case '2':
				InputBox(name, 20, "请输入修改后的姓名");
				p->name = name;
				break;
			case '3':
				InputBox(sex, 20, "请输入修改后的性别");
				p->sex = sex;
				break;
			case '4':
				InputBox(phone, 20, "请输入修改后的电话");
				p->phone = phone;
				break;
			case '5':
				InputBox(a, 20, "请输入修改后的身份证");
				p->a = a;
				break;
			case 6:
				InputBox(home, 20, "请输入修改住址");
				p->home = home;
				break;
			}
			break;
		}
		p = p->next;
	}
	settextstyle(25, 0, "楷体");
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	char arr[] = "已成功修改该学生的信息";
	outtextxy(440, 600, arr);
	if (!finded) {
		settextstyle(25, 0, "楷体");
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		char arr[] = "没有查询到该同学的信息";
		outtextxy(440, 600, arr);
	}

}


//删除学生信息
void deleteStudent(stu** head) {
	char keyword[20];
	InputBox(keyword, 20, "请输入要删除的学生姓名或学号：");

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
			free(pr); // 释放被删除节点的内存空间
			settextstyle(30, 0, "宋体");
			outtextxy(400, 400, "删除成功");

			return;
		}
		pr1 = pr;
		pr = pr->next;
	}
	outtextxy(300, 400, "没有找到该学生信息");
}


//查找学生
void searchstudent(stu* head) {
	char s[20];
	InputBox(s, 20, "请输入要查找的学生姓名或学号：");

	while (head != NULL) {       //字符截取函数substr
		if (head->numble == s || head->name == s) {
			settextstyle(20, 0, "宋体");
			outtextxy(10, 110, "查找成功");
			nodoLine(); // 绘制表格
			int x = 150; // 第一列的 x 坐标
			int y = 110; // 每行的 y 坐标
			outtextxy(x, y, head->numble.c_str());
			x += 130; // 列之间的间隔为 150
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
	settextstyle(30, 0, "宋体");
	outtextxy(400, 400, "没有该人信息");
}

void recordStudent(stu* head) {

	string s = "ab.txt";//打开一个写文件流
	fstream fout(s, ios::out | ios::app);
	//iOS：：out打开文件进行写操作
	//iOS：：app 在文件为追加方式写文件
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
//文件记录学生信息
void drawMenuItem(int x1, int y1, int x2, int y2, const char* text) {
	setfillcolor(BLUE);
	fillrectangle(x1, y1, x2, y2);
	settextstyle(15, 0, "微软黑体");
	setbkmode(TRANSPARENT);
	outtextxy((x1 + x2) / 2 - 30, (y1 + y2) / 2 - 5, text);
}
int currentPage = 0;
void table() {
	
	drawMenuItem(300, 600, 420, 620, "上一页");
	drawMenuItem(500, 600, 620, 620, "下一页");
	MOUSEMSG n;
	n = GetMouseMsg();
	if (n.x >= 300 && n.x <= 420 && n.y >= 600 && n.y <= 620) {
		setlinecolor(RED);
		rectangle(298, 598, 422, 622);
		if (n.uMsg == WM_LBUTTONDOWN) {
			// 如果按下鼠标左键实现相应功能.
			if (currentPage > 0) {
				currentPage--; // 切换到上一页
				cleardevice(); // 清除屏幕
				Display(head); // 显示上一页的学生信息
			}
		}
	}
	else if (n.x >= 500 && n.x <= 620 && n.y >= 600 && n.y <= 620) {
		setlinecolor(RED);
		rectangle(498, 598, 622, 622);
		if (n.uMsg == WM_LBUTTONDOWN) {
			// 如果按下鼠标左键实现相应功能.
			// 注意：这里需要添加逻辑以确保不会超过最大页面数量
			currentPage++; // 切换到下一页
			cleardevice(); // 清除屏幕
			Display(head); // 显示下一页的学生信息
		}
	}
	else {
		setlinecolor(WHITE);
		rectangle(298, 598, 422, 622);
		rectangle(498, 598, 622, 622);
	}
}

void showmenu() {//主页面函数
	string title = "通讯录管理系统";
	int m_w = 940, m_h = 640;
	initgraph(m_w, m_h, EX_SHOWCONSOLE);
	HWND hwnd = initgraph(m_w, m_h); // Get the window handle
	SetWindowText(hwnd, title.c_str());


	loadimage(&m_bk, "./images/abc.jpg", m_w, m_h);
	putimage(0, 0, &m_bk);

	drawMenuItem(370, 200, 570, 250, "显示学生");
	drawMenuItem(370, 255, 570, 305, "添加学生");
	drawMenuItem(370, 310, 570, 360, "删除学生");
	drawMenuItem(370, 365, 570, 415, "修改学生");
	drawMenuItem(370, 420, 570, 470, "查找学生");
	drawMenuItem(370, 475, 570, 525, "退出系统");
	while (1) {
		MOUSEMSG m;
		m = GetMouseMsg();
		//显示
		if (m.x >= 370 && m.x <= 570 && m.y >= 200 && m.y <= 250) {
			setlinecolor(RED);
			rectangle(368, 198, 572, 252);
			if (m.uMsg == WM_LBUTTONDOWN) {	//如果按下鼠标左键实现相应功能.
				cleardevice();
				putimage(0, 0, &m_bk);
				loadimage(&m_bk, "./images/abc.jpg", ::getwidth(), ::getheight());
				
				Display(head);
				
					break;
				}
			}
		
		else {	//当鼠标不在目标位置就覆盖之前的蓝色边框.
			setlinecolor(WHITE);
			rectangle(368, 198, 572, 252);
		}
		//添加
		if (m.x >= 370 && m.x <= 570 && m.y >= 255 && m.y <= 305) {
			setlinecolor(RED);
			rectangle(368, 253, 572, 302);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
				putimage(0, 0, &m_bk);
				loadimage(&m_bk, "./images/abc.jpg", ::getwidth(), ::getheight());
				addStudent(&head);
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的蓝色边框.
			setlinecolor(WHITE);
			rectangle(368, 253, 572, 302);
		}
		//删除通讯录
		if (m.x >= 370 && m.x <= 570 && m.y >= 310 && m.y <= 360) {
			setlinecolor(RED);
			rectangle(368, 312, 572, 362);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
				putimage(0, 0, &m_bk);
				loadimage(&m_bk, "./images/abc.jpg", ::getwidth(), ::getheight());
				deleteStudent(&head);
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的蓝色边框.
			setlinecolor(WHITE);
			rectangle(368, 312, 572, 362);
		}
		//修改通讯录
		if (m.x >= 370 && m.x <= 570 && m.y >= 365 && m.y <= 415) {
			setlinecolor(RED);
			rectangle(368, 367, 572, 417);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
				putimage(0, 0, &m_bk);
				loadimage(&m_bk, "./images/abc.jpg", ::getwidth(), ::getheight());
				modifyStudent(head);
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的蓝色边框.
			setlinecolor(WHITE);
			rectangle(368, 367, 572, 417);
		}
		//查找
		if (m.x >= 370 && m.x <= 570 && m.y >= 420 && m.y <= 470) {
			setlinecolor(RED);
			rectangle(368, 422, 572, 472);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
				putimage(0, 0, &m_bk);
				loadimage(&m_bk, "./images/abc.jpg", ::getwidth(), ::getheight());
				searchstudent(head);
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的蓝色边框.
			setlinecolor(WHITE);
			rectangle(368, 422, 572, 472);
		}
		//退出
		if (m.x >= 370 && m.x <= 570 && m.y >= 475 && m.y <= 525) {
			setlinecolor(RED);
			rectangle(368, 477, 572, 527);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.

				return;
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的蓝色边框.
			setlinecolor(WHITE);
			rectangle(368, 477, 572, 527);
		}
	}

}

ExMessage m_msg; // 消息
bool hasMsg() {
	return kbhit(); // 检查有按键输入吗
}

ExMessage& getMsg() {
	static ExMessage msg;
	msg.message = WM_KEYDOWN; //esc按键
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
		//检查有按键输入
		if (hasMsg()) {
			//按esc退回主页面
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