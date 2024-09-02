#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef int ElementType;

typedef int Position;
typedef struct LNode* List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(){
	List L=(List)malloc(sizeof(struct LNode));
	L->Last=-1;
	ElementType n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);
		L->Data[++L->Last]=t;
		
	}
	return L;
} /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList(List L){
	for(int i=0;i<=L->Last;i++){
		printf("%d ",L->Data[i]);
	}
	printf("\n");
	printf("Last = %d",L->Last);
} /* 裁判实现，细节不表 */
bool Insert(List L, int X){
	if(L->Last>=9){
		return false;
	}
	int t=0,sum=0;
	for(int i=0;i<=L->Last;i++){
		if(L->Data[i]==X) return false;
		if(L->Data[i]<X){
			t=i;
		
			break;
		}
			sum++;
	}
	
	
	if(sum==L->Last+1){
	L->Data[sum]=X;
		L->Last++;
		return true;
	}
	for (int k = L->Last; k >= t; k--) {
		L->Data[k + 1] = L->Data[k];
	}
	L->Data[t] = X;
	L->Last++;
	
	return true;
}
int main()
{
	List L;
	ElementType X;
	L= ReadInput();
	scanf("%d",&X);
	if (Insert(L, X) == false)
		printf("Insertion failed.\n");
	PrintList(L);
	free(L);
	return 0;
}



