// 包含自定义的任务头文件
#include "../include/tasks.h"

// 任务 1 函数的实现，计算大于 100 的数的阶乘
void task1() {
    // 定义一个整型变量用于存储用户输入的数
    int input_1;
    // 进入一个无限循环，直到用户输入符合要求的数
    while (true) {
        // 提示用户输入一个大于 100 的正整数
        std::cout << "Please enter a positive integer greater than 100: ";
        // 从标准输入读取用户输入的数
        std::cin >> input_1;
        // 检查输入的数是否大于 100 且为正数
        if (input_1 > 100 && input_1 > 0) break;
        // 如果输入不符合要求，提示用户重新输入
        std::cout << "Invalid input. Please try again." << std::endl;
    }
    // 定义一个向量用于存储阶乘结果，初始值为 1
    std::vector<int> result = {1};
    // 从 2 开始循环到用户输入的数，计算阶乘
    for (int i = 2; i <= input_1; ++i) {
        // 定义一个进位变量，初始值为 0
        int carry = 0;
        // 遍历结果向量中的每一位
        for (int& digit : result) {
            // 计算当前位乘以 i 再加上进位的结果
            int product = digit * i + carry;
            // 当前位更新为乘积的个位数
            digit = product % 10;
            // 进位更新为乘积除以 10 的商
            carry = product / 10;
        }
        // 处理剩余的进位
        while (carry > 0) {
            // 将进位的个位数添加到结果向量末尾
            result.push_back(carry % 10);
            // 进位更新为除以 10 的商
            carry /= 10;
        }
    }
    // 逆序遍历结果向量并输出每一位
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        std::cout << *it;
    }
    // 输出换行符
    std::cout << std::endl;
}    