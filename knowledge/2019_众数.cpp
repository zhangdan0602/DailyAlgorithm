//
// Created by ZD-Mac on 2021/3/9.
//
/*
 * 题目描述
Time Limit: 1000 ms
Memory Limit: 256 mb
某个序列有n个正整数，每个正整数都是m位数。某科研人员想统计该序列各个位的“众数”。

第i（1<=i<=m）位的众数是指，n个正整数的第i位出现次数最多的最小数字。

最低位（个位）是第1位，最高位是第m位。

输入输出格式
输入描述:
从标准输入读入数据。
输入的第一行包含两个正整数n,m，保证n<=10^5, m <= 6。
输入的第二行包含n个正整数。
同行相邻两个整数用一个空格隔开。
输出描述:
输出到标准输出。
输出共m行，每行一个整数，第i行表示第i位的众数。
输入输出样例
输入样例#:
复制
3 1
1 2 0
输出样例#:
复制
0
提示
第1位中，0,1,2各出现一次，所以众数是0.
题目来源
清华大学2019年机试题
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n, num;
    cin >> n >> m;
    /*vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }*/
    vector<vector<int>> res(m, vector<int>(n));

    for (int j = 0; j < n; ++j) {
        cin >> num;
//        cout << num << endl;
        for (int i = 0; i < m; ++i) {
            int yu = num % 10;
//            cout << yu << "\t" << num << endl;
            num /= 10;
            res[i][j] = yu;
        }
    }

//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cout << res[i][j] << "\t";
//        }
//        cout << endl;
//    }

    for (int i = 0; i < m; ++i) {
        vector<int> nums = res[i];
        vector<int> count(10, 0);
        for (int j = 0; j < n; ++j) {
            count[nums[j]]++;
        }
        int maxCnt = nums[0], index = 0;
        for (int j = 0; j < 10; ++j) {
            if (count[j] > maxCnt) {
                maxCnt = count[j];
                index = j;
            }
        }
        cout << index << endl;
    }
    return 0;
}