//
// Created by ZD-Mac on 2021/3/9.
//

/*
 * 题目描述
Time Limit: 1000 ms
Memory Limit: 256 mb
“众所周知，世界的本质是电。”

你在上课的时候听到了这句话，看到了讲台上的wnn正在施展她的“升次方”。

wnn的升次方是这样进行的：选取两个正整数a,m，计算出n=am。

由于你之前没有听课，现在你只知道n和m的值，你需要计算出a的值。

输入输出格式
输入描述:
从标准输入读入数据。
输入的包括一行两个正整数n,m，以空格隔开，含义如题目描述。
对于所有的输入数据，保证0<=lg(n)<=7*10^4，2<=m<=5，且存在正整数a使a^m=n。
其中，lg表示以10为底的对数。
输出描述:
输出到标准输出。
输出一行一个正整数，表示winn选取的a的值。
输入输出样例
输入样例#:
复制
4 2
输出样例#:
复制
2
提示
由于sqrt(4)=2，故输出2。
题目来源
清华大学2019年机试题
 */
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
//    for (int i = 0; i < n; ++i) {
//        if (pow(i, m) == n) {
//            cout << i << endl;
//            break;
//        }
//    }
    cout << pow(n, 1.0 / m) << endl;
    return 0;
}