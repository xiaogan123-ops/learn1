#include<stdio.h>
#include<stdlib.h>
struct link{
	int data;
	struct link *next;
};
struct link *AppendNote(struct link *hand,int data);
struct link *DeleteNote(struct link *hand,int data);
void PrintfNote(struct link *hand);
int main(void){
	int data;
	struct link *hand=NULL;
	while(1){
		scanf("%d",&data);
		if(data==-1)
			break;
		hand=AppendNote(hand,data);
	}
	scanf("%d",&data);
	hand=DeleteNote(hand,data);
	PrintfNote(hand);
	return 0;
}
struct link *AppendNote(struct link *hand,int data){
	struct link *pr=NULL,*pr1=hand;
	pr=(struct link*)malloc(sizeof(struct link));
	if(pr==NULL){
		exit(0);
	}
	if(hand==NULL){
		hand=pr;
	}else {
		while(pr1->next!=NULL){
			pr1=pr1->next;
		}
		pr1->next=pr;
	}
	pr->data=data;
	pr->next=NULL;
	return hand;
}
struct link *DeleteNote(struct link *hand,int data){
	struct link *pr1,*pr2;
	while(hand!=NULL && hand->data==data){
		pr2=hand;
		hand=hand->next;
		free(pr2);
	}
	if(hand==NULL){
		return NULL;
	}
	pr1=hand;
	pr2=hand->next;
	while(pr2!=NULL){
		if(pr2->data==data){
			pr1->next=pr2->next;
			free(pr2);
		}
		else {pr1=pr2;
		pr2=pr2->next;
	}
	}
	return hand;
}
void PrintfNote(struct link *hand){
	struct link *pr;
	int i=1;
	pr=hand;
	while(pr!=NULL){
		if(i==1){
			printf("%d",pr->data);
		}else printf("->%d",pr->data);
		i++;
		pr=pr->next;
	}
}

