#include <stdio.h>
#include <math.h>

int main() {
	double x1, y1, x2, y2;
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	
	double x = x1 + x2;
	double y = y1 + y2;
	
	// 将结果保留一位小数
	x = floor(x * 10 + 0.5) / 10; // 四舍五入保留一位小数
	y = floor(y * 10 + 0.5) / 10;
	
	// 输出结果，保证小数点后有一位数字
	if (x == (int)x) {
		printf("(%.1f, ", x);
	} else {
		printf("(%.1f, ", x);
	}
	if (y == (int)y) {
		printf("%.1f)\n", y);
	} else {
		printf("%.1f)\n", y);
	}
	
	return 0;
}

