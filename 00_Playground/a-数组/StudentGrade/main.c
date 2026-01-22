#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int max = 0;
	int sorces[5];
	for (int i = 0; i < 5;i++) {
		printf("请输入第%d个学生的成绩:\n",i+1 );
		scanf_s("%d", &sorces[i]);
		if (i >= 1 && max < sorces[i-1]) {
			max = sorces[i-1];
		}
	}
	printf("最大数是:%d", max);
	return 0;
}