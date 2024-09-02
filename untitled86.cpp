#include <stdio.h>

struct colleague
{
	char name[11];
	int birth;
	char phone[18];
};

void sort_age(struct colleague *p, int n);

int main()
{
	struct colleague my_friend[10];
	int i, n;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s %d %s", my_friend[i].name, &my_friend[i].birth, my_friend[i].phone);
	sort_age(my_friend, n);
	
}

void sort_age(struct colleague *p, int n)
{
	struct colleague temp;
	int i, j;
	
	for (i = 0; i < n - 1; i++)    //冒泡排序
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if ((p+j)->birth > (p+j+1)->birth)
			{
				temp = *(p+j);				
				*(p+j) = *(p+j+1);
				*(p+j+1) = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%s %d %s\n", (p+i)->name, (p+i)->birth, (p+i)->phone);
}
