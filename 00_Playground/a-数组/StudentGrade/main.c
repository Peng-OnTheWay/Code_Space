#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int max = 0;
	float averge = 0;
	float sum = 0;
	int sorces[5];
	for (int i = 0; i < 5;i++) {
		printf("请输入第%d个学生的成绩:\n",i+1 );
		scanf_s("%d", &sorces[i]);
		if (max < sorces[i]) {
			max = sorces[i];
		}
		sum = sorces[i] + sum;
		averge =sum / (i + 1);
	}
	printf("最好的成绩是:%d\n", max);
	printf("总分数:%f\n", sum);
	printf("平均成绩是:%f\n", averge);
	return 0;
}