#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Insert( List L, ElementType X );

int main()
{
	List L;
	ElementType X;
	L = Read();
	scanf("%d", &X);
	L = Insert(L, X);
	Print(L);
	return 0;
}
List Read(){
	int n;
	scanf("%d",&n);
	
    List L=(List)malloc(sizeof(struct Node));
	L->Next=NULL;
	List pr=L;
	for(int i=0;i<n;i++){
		
	  List L1=(List)malloc(sizeof(struct Node));
		scanf("%d",&L1->Data);
		pr->Next=L1;
		pr=L1;
		
	}
	pr->Next=NULL;
	return L;
}
void Print( List L ){
	L=L->Next;
	while(L!=NULL){
		printf("%d ",L->Data);
		L=L->Next;
	}
}
List Insert( List L, ElementType X ){
	List t,pr2=L;
	t=L->Next;
	List pr=(List)malloc(sizeof(struct Node));
	pr->Data=X;
	pr->Next=NULL;
	
	while(t!=NULL){
		if(t->Data<pr->Data){
			pr2=t;
			t=t->Next;
		}else break;
		
	}
	
	pr->Next=pr2->Next;
	pr2->Next=pr;
	return L;
}
/* 你的代码将被嵌在这里 */
