#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (结构体定义保持不变)
typedef struct Student {
    char id[10];
    char name[10];
    int age;
    char sex[5];
} Student;

typedef struct Node {
    Student data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;    // 永远指向队伍的第一个人（老鹰）
    Node* current = NULL; // 永远指向队伍的最后一个人（用来快速加人）
    Node* newNode = NULL; // 这是一个临时工，用来造新节点

    // ==========================================
    // 添加第 1 个学生
    // ==========================================
    newNode = (Node*)malloc(sizeof(Node)); // 造盒子
    newNode->next = NULL; // 新来的后面暂时没人，记得把它的next设为NULL！

    printf("请输入第1个学生 (学号 姓名 年龄 性别): ");
    scanf("%s %s %d %s", newNode->data.id, newNode->data.name, &newNode->data.age, newNode->data.sex);

    if (head == NULL) {
        // 队伍是空的
        head = newNode;      // 新人既是头
        current = newNode;   // 新人也是尾
    }
    else {
        // (这段逻辑第1次不会执行，留给后面看)
        current->next = newNode;
        current = newNode;
    }

    // 【重要！】千万不要在这里写 free(current)！

    printf("成功添加! 现在的头节点是: %s\n\n", head->data.name);


    // ==========================================
    // 添加第 2 个学生
    // ==========================================
    newNode = (Node*)malloc(sizeof(Node)); // 【注意】这里直接复用变量，不要写 Node*
    newNode->next = NULL; // 每次新节点产生，都要把它的尾巴封死

    printf("请输入第2个学生 (学号 姓名 年龄 性别): ");
    scanf("%s %s %d %s", newNode->data.id, newNode->data.name, &newNode->data.age, newNode->data.sex);

    if (head == NULL) {
        // 如果队伍还是空的（防守逻辑）
        head = newNode;
        current = newNode;
    }
    else {
        // 【核心：尾插法逻辑】
        // 1. 让原本的最后一个人(current)的手，抓住新人(newNode)
        current->next = newNode;
        // 2. 更新“最后一个人”的称号，现在新人变成了最后一个人
        current = newNode;
    }

    // 【重要！】同样不要 free！

    printf("成功添加! 现在的头节点是: %s\n", head->data.name);

    return 0;
}