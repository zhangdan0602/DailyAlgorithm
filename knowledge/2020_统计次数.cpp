//
// Created by ZD-Mac on 2021/3/16.
//

/*
 * 题目描述
Time Limit: 1000 ms
Memory Limit: 256 mb
给定两个正整数 n 和 k(1≤k≤9)，求从 1 到 n 这 n 个正整数的十进制表示中 k 出现的次数。

输入输出格式
输入描述:
从标准输入读入数据。
输入的第一行包含两个正整数 n 和 k，保证 n≤10^6 和 1≤k≤9。
输出描述:
输出到标准输出。
输出一个整数，表示答案。
输入输出样例
输入样例#:
复制
12 1
输出样例#:
复制
5
提示
从 1 到 12 这些整数中包含 1 的数字有 1,10,11,12，一共出现了 5 次 1。
题目来源
清华大学2020年机试题
 */
#include <iostream>

using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        int cnt = 0;
        for (int num = 1; num <= n; ++num) {
            int t = num;
            while (t > 0) {
                if (t % 10 == k) {
                    cnt++;
                }
                t /= 10;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}