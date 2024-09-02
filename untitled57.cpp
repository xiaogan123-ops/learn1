#include<stdio.h>
#include<stdlib.h>
struct link{
	int data;
	struct link *next;
};
struct link *AppendNote(struct link *hand,int data);
struct link *InsertNote(struct link *hand,int data);
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
	PrintfNote(hand);
	hand=InsertNote(hand,data);
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
	}
	else {
		while(pr1->next!=NULL){
			pr1=pr1->next;
		}
		pr1->next=pr;
	}
	pr->data=data;
	pr->next=NULL;
	return hand;
}
struct link *InsertNote(struct link *hand,int data){
	struct link *pr,*pr2=hand;
	pr=(struct link*)malloc(sizeof(struct link));
	if(pr==NULL){
		exit(0);
	}
	pr->data=data;
	pr->next=NULL;
   if(hand==NULL||hand->data>data){
	   pr->next=hand;
	   hand=pr;
   }else {
	   while(pr2->next!=NULL&&pr2->next->data<data){
		   pr2=pr2->next;
	   }
	   pr->next=pr2->next;
	   pr2->next=pr;
   }
	return hand;
}
void PrintfNote(struct link *hand){
	struct link *pr=hand;
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
