// 包含自定义的任务头文件
#include "../include/tasks.h"

// 任务 5 函数的实现，计算第 n 个斐波那契数，其中 n > 100
void task5() {
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
    // 如果输入为 1，直接输出 1 并返回
    if (input_1 == 1) {
        std::cout << 1 << std::endl;
        return;
    }
    // 如果输入为 2，直接输出 1 并返回
    if (input_1 == 2) {
        std::cout << 1 << std::endl;
        return;
    }
    // 定义两个向量分别用于存储前一个斐波那契数和当前斐波那契数，初始值都为 1
    std::vector<int> prev = {1};
    std::vector<int> current = {1};
    // 从第 3 项开始循环计算斐波那契数
    for (int i = 3; i <= input_1; ++i) {
        // 定义一个向量用于存储下一个斐波那契数
        std::vector<int> next;
        // 定义一个进位变量，初始值为 0
        int carry = 0;
        // 遍历前一个和当前斐波那契数向量，逐位相加
        for (size_t j = 0; j < std::max(prev.size(), current.size()); ++j) {
            // 计算当前位相加再加上进位的结果
            int sum = carry;
            if (j < prev.size()) sum += prev[j];
            if (j < current.size()) sum += current[j];
            // 将结果的个位数添加到下一个斐波那契数向量中
            next.push_back(sum % 10);
            // 进位更新为结果除以 10 的商
            carry = sum / 10;
        }
        // 如果还有进位，将进位添加到下一个斐波那契数向量末尾
        if (carry > 0) {
            next.push_back(carry);
        }
        // 更新前一个斐波那契数为当前斐波那契数
        prev = current;
        // 更新当前斐波那契数为下一个斐波那契数
        current = next;
    }
    // 逆序遍历当前斐波那契数向量并输出每一位
    for (auto it = current.rbegin(); it != current.rend(); ++it) {
        std::cout << *it;
    }
    // 输出换行符
    std::cout << std::endl;
}    