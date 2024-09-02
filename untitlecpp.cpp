#include<iostream>
using namespace std;
struct linklist{
	int t;
	struct linklist *next;
};
int main(){
	struct linklist {
		int data;
		linklist* next;
	};
	linklist* creat(int n) {//创建含有n个节点的链表
		linklist* head;
		linklist* node;
		linklist* end;
		head = new linklist;//申请表头空间
		end = head;
		head->data = n;
		//可以选择从表头开始存放所需数据，也可以选择独立表头；
		//这里选择独立表头，并且表头 data表示节点数；
		for (int j = 1; j <= n; j++) {
			node = new linklist;
			node->data = j;//存放数据
			end->next = node;
			end = node;
			//靠end的移动来创建链表
		}
		return head;//头指针表示一个链表
	}
}
