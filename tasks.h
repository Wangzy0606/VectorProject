// 头文件保护，防止头文件被重复包含
#ifndef TASKS_H
#define TASKS_H

// 包含输入输出流库，用于输入输出操作
#include <iostream>
// 包含向量容器库，用于存储和操作动态数组
#include <vector>

// 声明任务 1 函数，用于计算大于 100 的数的阶乘
void task1();
// 声明任务 2 函数，用于计算 2 的 n 次方，其中 n > 64
void task2();
// 声明任务 3 函数，用于计算 2 的 n1 次方加 2 的 n2 次方，其中 n1, n2 > 64
void task3();
// 声明任务 4 函数，用于计算 2 的 n1 次方减 2 的 n2 次方，其中 n1, n2 > 64 且 n1 > n2
void task4();
// 声明任务 5 函数，用于计算第 n 个斐波那契数，其中 n > 100
void task5();

// 结束头文件保护
#endif    