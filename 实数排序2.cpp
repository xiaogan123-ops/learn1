#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i, j;
	scanf("%d", &n);
	
	double* arr = (double*)malloc(sizeof(double) * n);
	
	// 输入n个实数
	for (i = 0; i < n; i++)
	{
		scanf("%lf", arr + i);
	}
	
	// 使用冒泡排序算法将数组从大到小排列
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (*(arr + j) < *(arr + j + 1))
			{
				double temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
	
	// 输出排列结果
	for (i = 0; i < n; i++)
	{
		printf("%.2lf", *(arr + i));
		if (i != n - 1)
			printf(" ");
	}
	
	free(arr);
	return 0;
}

