#include <stdio.h>
#include <stdlib.h>

struct link
{
	int data;
	struct link *next;
};

struct link *AppendNode(struct link *head,int data);
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);

int main()
{	
	int data = 0;
	struct link *head = NULL;      /* 链表头指针 */
	while (1)
	{
		scanf("%d",&data);
		if (data==-1)
			break;
		
		head = AppendNode(head,data);/* 向head为头指针的链表末尾添加节点 */
	}
	DisplyNode(head);        /* 显示当前链表中的各节点信息 */
	DeleteMemory(head);           /* 释放所有动态分配的内存 */
	return 0;
}

struct link *AppendNode(struct link *head, int data) {
	struct link *p = NULL, *q = head;
	p = (struct link*)malloc(sizeof(struct link));
	if (p == NULL) {
		exit(0);
	}
	if (head == NULL) {
		head = p;
	} else {
		while (q->next != NULL) {
			q = q->next;
		}
		q->next = p;
	}
	p->data = data;
	p->next = NULL;
	return head;
}
void DisplyNode(struct link &head) {
	struct link *p;
	p = &head;
	int i = 1;
	while (p != NULL) {
		if (i == 1) {
			printf("%d", p->data);
		} else {
			printf("->%d", p->data);
		}
		i++;
		p = p->next;
	}
}
void DeleteMemory(struct link*head) {
	struct link *p = NULL;
	struct link *pr = head;
	while (pr != NULL) {
		p = pr;
		pr = pr->next;
		free(p);
	}
}
