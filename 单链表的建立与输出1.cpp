#include<stdio.h>
#include<stdlib.h>
struct link {
	int data;
	struct link *next;
};
struct link *AppendNote(struct link *head,int data);
void Printf(struct link *head);
int main(void){
	int data;
	struct link *head=NULL;
	while(1){
		scanf("%d",&data);
		if(data==-1)
			break;
		head=AppendNote(head,data);
	}
	Printf(head);
	return 0;
}
struct link *AppendNote(struct link *head,int data){
	struct link *pr=NULL,*pr1=head;
	pr=(struct link*)malloc(sizeof(struct link));
	if(pr==NULL){
		exit(0);
	}
	if(head==NULL){
		head=pr;
	}else {
		while(pr1->next!=NULL){
			pr1=pr1->next;
		}
		pr1->next=pr;
	}
	pr->data=data;
	pr->next=NULL;
	return head;
}
void Printf(struct link *head){
	struct link *pr=head;
	int i=1;
	if(head==NULL){
		printf("NULL");
	}
	while(pr!=NULL){
		if(i==1){
			printf("%d",pr->data);
		}else printf(",%d",pr->data);
		i++;
		pr=pr->next;
	}
}
