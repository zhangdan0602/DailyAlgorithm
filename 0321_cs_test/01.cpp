//
// Created by ZD-Mac on 2021/3/21.
//
/*
 * Prime
时间限制： 0.2 秒

空间限制： 512 MiB

题目描述
输入一个正整数 𝑥，请你在 𝑥 后面添加若干位数字（不能不添加；添加的部分不得以数字 0 开头），使得结果为质数，在这个前提下所得的结果应尽量小。

输入格式
从标准输入读入数据。

仅一行，输入一个正整数 𝑥。

输出格式
输出到标准输出。

输出一行，包含一个整数，表示所得的结果。

样例1输入
1
样例1输出
11
样例2输入
20
样例2输出
2011
子任务
输入保证 1≤𝑥≤100。

本题共有 100 个测试点，每个测试点 1 分。

语言及编译选项信息

#	名称	编译器	额外参数	代码长度限制（B）
0	g++ with std17	g++	-O2 -std=c++17 -DONLINE_JUDGE	65536
1	g++	g++	-O2 -DONLINE_JUDGE	65536
2	gcc with std17	gcc	-O2 -std=c17 -DONLINE_JUDGE	65536
3	gcc	gcc	-O2 -DONLINE_JUDGE	65536
4	java	javac		65536
5	python	python		65536
6	python3	python3		65536
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 100010;
vector<int> prime(MAXN + 1);
map<string, int> mapPrime;

void getPrime() {
    for (int i = 2; i <= MAXN; i++) {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int stringToInt(string s) {
    int len = s.length();
    int res = 0;
    for (int i = 0; i < len; ++i) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

int main() {
//    getPrime();
//    for (int k = 1; k < 101; ++k) {
//        vector<string> setPrime;
//        for (int i = 1; i < prime.size(); ++i) {
//            setPrime.push_back(to_string(prime[i]));
//        }
//        int cnt = 0;
//        vector<string> res;
//        int minVal = 100000000;
//        string strInput = to_string(k);
//        int a, b, ret, diff = 0;
//        for (string pri: setPrime) {
//            if (pri.find(strInput) == 0) {
//                if (pri.length() > strInput.length()) {
//                    string sub = pri.substr(0, strInput.length() + 1);
//                    int l = sub.length();
//                    if (sub[l - 1] != '0') {
//                        a = stringToInt(pri);
//                        b = stringToInt(strInput);
//                        diff = a - b;
//                        if (diff < minVal) {
//                            minVal = diff;
//                            ret = a;
////                        cout << a << "\t" << b << "\t" << diff << "\t" << minVal << endl;
//                        }
////                    res.push_back(pri);
////                    cout << pri << endl;
////                    cnt++;
//                    }
//                }
//            }
//        }
////    cout << cnt << endl;
//        cout << k << "\t" << ret << endl;
////    cout << stringToInt("5001");
//    }


    int m;
    cin >> m;
    vector<string> setPrime;
    for (int i = 1; i < prime.size(); ++i) {
        setPrime.push_back(to_string(prime[i]));
    }
    int cnt = 0;
    vector<string> res;
    int minVal = 100000000;
    string strInput = to_string(m);
    int a, b, ret, diff = 0;
    for (string pri: setPrime) {
        if (pri.find(strInput) == 0) {
            if (pri.length() > strInput.length()) {
                string sub = pri.substr(0, strInput.length() + 1);
                int l = sub.length();
                if (sub[l - 1] != '0') {
                    a = stringToInt(pri);
                    b = stringToInt(strInput);
                    diff = a - b;
                    if (diff < minVal) {
                        minVal = diff;
                        ret = a;
//                        cout << a << "\t" << b << "\t" << diff << "\t" << minVal << endl;
                    }
//                    res.push_back(pri);
//                    cout << pri << endl;
//                    cnt++;
                }
            }
        }
    }
//    cout << cnt << endl;
    cout << ret << endl;
//    cout << stringToInt("5001");
    return 0;
}
