//
// Created by ZD-Mac on 2021/3/16.
//

/*
 * 题目描述
Time Limit: 1000 ms
Memory Limit: 256 mb
有一个特殊的 n 行 m 列的矩阵 Aij(1≤i≤n,1≤j≤m)，每个元素都是正整数，每一行和每一列都是独立的等差数列。
 在某一次故障中，这个矩阵的某些元素的真实值丢失了，被重置为 0。现在需要你想办法恢复这些元素，
 并且按照行号和列号从小到大的顺序（行号为第一关键字，列号为第二关键字，从小到大）输出能够恢复的元素。

输入输出格式
输入描述:
从标准输入读入数据。

输入的第一行包含两个正整数 n 和 m，保证 n≤10^3 和 m≤10^3。

接下来 n 行，每行 m 个整数，表示整个矩阵，保证 1≤Aij≤10^9。如果 Aij 等于 0，表示真实值丢失的元素。
输出描述:
输出若干行，表示所有能够恢复的元素。每行三个整数 i,j,x，表示 Aij 的真实值是 x。
输入输出样例
输入样例#:
复制
3 4
1 2 0 0
0 0 0 0
3 0 0 0
输出样例#:
复制
1 3 3
1 4 4
2 1 2
提示
可以恢复 3 个元素， A13 的真实值是 3，A14 的真实值是 4，A21 的真实值是 2。
题目来源
清华大学2020年机试题
 */
#include <vector>

using namespace std;

int main() {
    // 输入放入vec
    // 每行差 设置count<2
    // 每列差 同样设置count<2
    // 更新每行和每列中0的数，只更新一次
    // 最后判断不同于原数组的数即可
    int m, n;
    vector<vector<int>> vec;
    for (int i = 0; i < ; ++i) {
        
    }
    int row = 0, col = 0;
    for (int i = 0; i < row; ++i) {
        int not0 = 0;
        for (int j = 0; j < col; ++j) {
            if (vec[i][j] != 0) {
                not0++;
            }
        }
        if (not0 >= 2) {
            int first = -1, second = -1;
            for (int j = 0; j < col; ++j) {
                if (vec[i][j] != 0 && first == -1) {
                    first = j;
                } else if (vec[i][j] != 0 && first > -1 && second == -1) {
                    second = j;
                    break;
                }
            }
            int ave = (vec[i][second] - vec[i][first]) / (second - first);
            for (int j = first; j < second; ++j) {
                if (first + 1 < col) {
                    vec[i][first + 1] = vec[i][first] + ave;
                }
            }
            for (int j = second; j < col; ++j) {
                if (j + 1 < col) {
                    vec[i][j + 1] = vec[i][j] + ave;
                }
            }
            for (int j = first; j >= 0; j--) {
                if (j - 1 >= 0) {
                    vec[i][j - 1] = vec[i][j] - ave;
                }
            }
        }
    }
    // 列遍历

    return 0;
}