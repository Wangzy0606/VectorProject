// 包含自定义的任务头文件
#include "../include/tasks.h"

// 任务 2 函数的实现，计算 2 的 n 次方，其中 n > 64
void task2() {
    // 定义一个整型变量用于存储用户输入的数
    int input_1;
    // 进入一个无限循环，直到用户输入符合要求的数
    while (true) {
        // 提示用户输入一个大于 64 的正整数
        std::cout << "Please enter a positive integer greater than 64: ";
        // 从标准输入读取用户输入的数
        std::cin >> input_1;
        // 检查输入的数是否大于 64 且为正数
        if (input_1 > 64 && input_1 > 0) break;
        // 如果输入不符合要求，提示用户重新输入
        std::cout << "Invalid input. Please try again." << std::endl;
    }
    // 定义一个向量用于存储结果，初始值为 1
    std::vector<int> result = {1};
    // 循环 n 次，计算 2 的 n 次方
    for (int i = 0; i < input_1; ++i) {
        // 定义一个进位变量，初始值为 0
        int carry = 0;
        // 遍历结果向量中的每一位
        for (int& digit : result) {
            // 计算当前位乘以 2 再加上进位的结果
            int product = digit * 2 + carry;
            // 当前位更新为乘积的个位数
            digit = product % 10;
            // 进位更新为乘积除以 10 的商
            carry = product / 10;
        }
        // 如果还有进位，将进位添加到结果向量末尾
        if (carry > 0) {
            result.push_back(carry);
        }
    }
    // 逆序遍历结果向量并输出每一位
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        std::cout << *it;
    }
    // 输出换行符
    std::cout << std::endl;
}    