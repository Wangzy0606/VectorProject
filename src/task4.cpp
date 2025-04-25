// 包含自定义的任务头文件
#include "../include/tasks.h"

// 任务 4 函数的实现，计算 2 的 n1 次方减 2 的 n2 次方，其中 n1, n2 > 64 且 n1 > n2
void task4() {
    // 定义两个整型变量用于存储用户输入的两个数
    int input_1, input_2;
    // 进入一个无限循环，直到用户输入符合要求的两个数
    while (true) {
        // 提示用户输入两个大于 64 且 n1 > n2 的正整数
        std::cout << "Please enter two positive integers greater than 64 and input_1 > input_2: ";
        // 从标准输入读取用户输入的两个数
        std::cin >> input_1 >> input_2;
        // 检查输入的两个数是否都大于 64 且为正数，同时 n1 大于 n2
        if (input_1 > 64 && input_1 > 0 && input_2 > 64 && input_2 > 0 && input_1 > input_2) break;
        // 如果输入不符合要求，提示用户重新输入
        std::cout << "Invalid input. Please try again." << std::endl;
    }
    // 定义两个向量分别用于存储 2 的 n1 次方和 2 的 n2 次方的结果，初始值都为 1
    std::vector<int> num1 = {1};
    std::vector<int> num2 = {1};
    // 循环 n1 次，计算 2 的 n1 次方
    for (int i = 0; i < input_1; ++i) {
        // 定义一个进位变量，初始值为 0
        int carry = 0;
        // 遍历 num1 向量中的每一位
        for (int& digit : num1) {
            // 计算当前位乘以 2 再加上进位的结果
            int product = digit * 2 + carry;
            // 当前位更新为乘积的个位数
            digit = product % 10;
            // 进位更新为乘积除以 10 的商
            carry = product / 10;
        }
        // 如果还有进位，将进位添加到 num1 向量末尾
        if (carry > 0) {
            num1.push_back(carry);
        }
    }
    // 循环 n2 次，计算 2 的 n2 次方
    for (int i = 0; i < input_2; ++i) {
        // 定义一个进位变量，初始值为 0
        int carry = 0;
        // 遍历 num2 向量中的每一位
        for (int& digit : num2) {
            // 计算当前位乘以 2 再加上进位的结果
            int product = digit * 2 + carry;
            // 当前位更新为乘积的个位数
            digit = product % 10;
            // 进位更新为乘积除以 10 的商
            carry = product / 10;
        }
        // 如果还有进位，将进位添加到 num2 向量末尾
        if (carry > 0) {
            num2.push_back(carry);
        }
    }
    // 补齐两个向量的长度，使它们长度相等
    while (num1.size() < num2.size()) num1.push_back(0);
    while (num2.size() < num1.size()) num2.push_back(0);
    // 定义一个向量用于存储两个结果相减的差
    std::vector<int> diff;
    // 定义一个借位变量，初始值为 0
    int borrow = 0;
    // 遍历两个向量的每一位，逐位相减
    for (size_t i = 0; i < num1.size(); ++i) {
        // 计算当前位相减再减去借位的结果
        int temp = num1[i] - num2[i] - borrow;
        // 如果结果小于 0，需要借位
        if (temp < 0) {
            // 结果加上 10 并更新借位为 1
            temp += 10;
            borrow = 1;
        } else {
            // 否则借位更新为 0
            borrow = 0;
        }
        // 将结果添加到差向量中
        diff.push_back(temp);
    }
    // 去除差向量末尾的 0
    while (diff.size() > 1 && diff.back() == 0) {
        diff.pop_back();
    }
    // 逆序遍历差向量并输出每一位
    for (auto it = diff.rbegin(); it != diff.rend(); ++it) {
        std::cout << *it;
    }
    // 输出换行符
    std::cout << std::endl;
}    