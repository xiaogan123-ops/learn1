#include<stdio.h>
#include<stdlib.h>
struct link {
	int data;
	struct link *next;
};
struct link *AppendNode(struct link *hand,int data);
void DisplyNode(struct link *hand);
void DeleteMemory(struct link *hand);
struct link *DeleteNode(struct link *hand,int data);
int main(void){
	int data;
	struct link *hand=NULL;
	while(1){
		scanf("%d",&data);
		if(data==-1)
			break;
		hand=AppendNode(hand,data);
	}
	DisplyNode(hand);
	scanf("%d",&data);
	hand=DeleteNode(hand,data);
	DisplyNode(hand);
	DeleteMemory(hand);
	return 0;
}
struct link *AppemdNote(struct link *hand,int data){
	struct link *p=NULL,*q=hand;
	p=(struct link*)malloc(sizeof(struct link));
	if(p==NULL){
		exit(0);
	}
	if(hand==NULL){
		hand=p;
	}else{
		while(q->next!=NULL){
			q=q->next;
		}
		q->next=p;
	}
	p->data=data;
	p->next=NULL;
}
void DisplyNote(struct link *hand){
	struct link*p;
	p=hand;
	int i=1;
	while(1){
		if(i==1){
			printf("%d",p->data);
		}else printf("->%d",p->data);
		i++;
		p=p->next;
	}
}
void DeleteMemory(struct link *hand){
	struct link *p=NULL;
	struct link *pr=hand;
	while(pr!=NULL){
		p=pr;
		pr=pr->next;
		free(p);
	}
}
DeleteNote(struct link *hand,int data){
	struct link *p,*q;
	q=hand;
	while(q!=NULL){
		if(q->data==data){
			if(q==hand)
				hand=q->next;
			else p->data=q->data;
		}else {
			p=q;
		}
		q=q->next;
	}
	return hand;
}


