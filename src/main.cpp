// 包含自定义的任务头文件
#include "../include/tasks.h"
// 包含输入输出流库，用于输入输出操作
#include <iostream>

// 主函数，程序的入口点
int main() {
    // 定义一个整型变量用于存储用户的选择
    int choice;
    // 进入一个无限循环，直到用户选择退出
    while (true) {
        // 输出菜单提示信息，让用户选择要执行的任务
        std::cout << "\nSelect a function:\n"
                  << "1. Calculate factorial of a number greater than 100\n"
                  << "2. Calculate 2^n where n > 64\n"
                  << "3. Calculate 2^n1 + 2^n2 where n1, n2 > 64\n"
                  << "4. Calculate 2^n1 - 2^n2 where n1, n2 > 64 and n1 > n2\n"
                  << "5. Calculate the nth Fibonacci number where n > 100\n"
                  << "0. Exit\n"
                  << "Enter your choice: ";
        // 从标准输入读取用户的选择
        std::cin >> choice;

        // 如果用户选择 0，退出循环
        if (choice == 0) {
            break;
        }

        // 根据用户的选择，调用相应的任务函数
        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            default:
                // 如果用户输入的选择无效，提示用户重新输入
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    // 主函数正常结束，返回 0
    return 0;
}    