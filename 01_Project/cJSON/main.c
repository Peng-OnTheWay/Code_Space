#define _CRT_SECURE_NO_WARNINGS // 必须放在第一行，避免VS报错
#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main() {
    // ---------------------------------------------------------
    // 第一步：创建“树根” (Root Object)
    // ---------------------------------------------------------
    // 所有的 JSON 数据必须依附于一个根节点，就像大树的根一样
    cJSON* root = cJSON_CreateObject(); //

    // ---------------------------------------------------------
    // 第二步：挂载叶子节点 (添加键值对)
    // ---------------------------------------------------------

    // 1. 添加字符串: "device_id": "STM32_001"
    // cJSON_AddStringToObject 是一个极其常用的辅助函数，它自动创建节点并挂载
    cJSON_AddStringToObject(root, "device_id", "STM32_001"); //

    // 2. 添加数字: "battery": 85
    cJSON_AddNumberToObject(root, "battery", 85); //

    // ---------------------------------------------------------
    // 第三步：创建并挂载数组 (Array)
    // ---------------------------------------------------------
    // 目标是: "sensors": [23.5, 60.2]

    // 准备好C语言的原生数组
    double sensor_data[] = { 23.5, 60.2 };

    // 使用 cJSON_CreateDoubleArray 一次性把 C数组 转换成 JSON数组节点
    cJSON* sensor_array = cJSON_CreateDoubleArray(sensor_data, 2); //

    // 把这个数组节点挂载到 root 上，名字叫 "sensors"
    cJSON_AddItemToObject(root, "sensors", sensor_array); //

    // ---------------------------------------------------------
    // 第四步：打印输出 (Serialization)
    // ---------------------------------------------------------
    // cJSON_Print 会自动分配内存，把整个树结构转换成字符串
    char* json_out = cJSON_Print(root); //

    printf("我的第一个JSON包:\n%s\n", json_out);

    // ---------------------------------------------------------
    // 第五步：清理现场 (最重要的内存管理！)
    // ---------------------------------------------------------

    // 1. 释放 JSON 树
    // 注意：只需要释放根节点(root)，cJSON 会自动顺藤摸瓜释放所有子节点(sensors等)
    cJSON_Delete(root); //

    // 2. 释放打印出来的字符串
    // cJSON_Print 内部使用了 malloc，所以这里必须用 free，否则会内存泄露
    free(json_out);     //

    // 暂停一下看结果
    system("pause");
    return 0;
}