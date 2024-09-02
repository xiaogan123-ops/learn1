#include<stdio.h>
#include<stdlib.h>
struct link {
	int date;
	struct link *next;
};
struct link *AppendNode(struct link *head, int date);
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);
int main() {
	int date;
	struct link *head = NULL;
	while (1) {
		scanf("%d", &date);
		if (date == -1)
			break;
		head = AppendNode(head, date);
	}
    DisplyNode(head);  
	DeleteMemory(head);
	return 0;
}
struct link *AppendNode(struct link *head, int date) {
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
	p->date = date;
	p->next = NULL;
	return head;
}
void DisplyNode(struct link &head) {
	struct link *p;
	p = &head;
	int i = 1;
	while (p != NULL) {
		if (i == 1) {
			printf("%d", p->date);
		} else {
			printf("->%d", p->date);
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
