#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	char id[10];
	char name[10];
	int age;
	char sex[1];
}Student;

//定义链表
typedef struct Node {
	Student data;
	struct Node* next;
}Node;

Node* createStudent(){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("内存分配失败\n");
		exit(1);
	}
	printf("请输入学号\n");
	scanf("%s", newNode->data.id);
	printf("请输入姓名\n");
	scanf("%s", newNode->data.name);
	printf("请输入年龄\n");
	scanf("%d",newNode->data.age);
	getchar();
	printf("请输入性别(M/F):\n");
	scanf("%c",newNode->data.sex);
	newNode->next = NULL;
	return newNode;
}
void addStudent(Node** head) {
	Node* newNode = createStudent();
	if (*head == NULL) {
		head = newNode;
	}
	else {
		Node p = *head;
		while (p.next != NULL) {
			p = p.next;
		}
		p.next = newNode;
	}
	printf("学生信息添加成功！\n");
}

}

int main() {
	Node* head = NULL;



}