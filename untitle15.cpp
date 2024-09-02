#include<stdio.h>
#include<stdlib.h>
struct link{
	int data;
	struct link *next;
};
struct link *AppendNote(struct link *head,int data);
struct link *DeleteNote(struct link *head,int data);
void PintfNote(struct link *head);
int main(void){
	int data;
	struct link *head=NULL;
	while(1){
		scanf("%d",&data);
		if(data==-1)
		break;
		head=AppendNote(head,data);
	}
	scanf("%d",&data);
		PintfNote(head);
	head=DeleteNote(head,data);
	PintfNote(head);
	return 0;
}
struct link *AppendNote(struct link *head,int data){
	struct link *pr=NULL,*pr1=head;
	pr=(struct link *)malloc(sizeof(struct link));
	if(pr==NULL){
		exit(0);
	}
	if(head==NULL){
		head=pr;
	}else {
		while(pr1->next!=NULL){
			pr1=pr1->next;
		}pr1->next=pr;
	}
	pr->data=data;
	pr->next=NULL;
	return head;
}
struct link *DeleteNote(struct link *head,int data){
	struct link *pr,*pr1=head;
	if(head==NULL){
		return NULL;
	}
	while(pr1!=NULL){
		if(pr1->data==data){
			if(pr1==head){
				head=head->next;
			}else pr->next=pr1->next;
		}else pr=pr1;
		pr1=pr1->next;
	}
	return head;
}
void PintfNote(struct link *head){
	struct link *pr=head;
	int i=1;
	while(pr!=NULL){
		if(i==1){
			printf("%d",pr->data);
		}else printf("->%d",pr->data);
		i++;
		pr=pr->next;
	}
	printf("\n");
}
