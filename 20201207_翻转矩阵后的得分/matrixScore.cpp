//
// Created by ZD-Mac on 2020-12-07.
//

/*
 * 有一个二维矩阵 A 其中每个元素的值为 0 或 1 。

移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。

在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。

返回尽可能高的分数。

 

示例：

输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
输出：39
解释：
转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 

提示：

1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] 是 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/score-after-flipping-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
// row
// column
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            changeRow(A, i);
        }
        for (int j = 1; j < A[0].size(); ++j) {
            changeColumn(A, j);
        }
        for (int k = 0; k < A.size(); ++k) {
            for (int m = 0; m < A[k].size(); ++m) {
                sum += pow(2, A[k].size() - m - 1) * A[k][m];
            }
        }
        return sum;
    }
    void changeRow(vector<vector<int>>& A, int index){
        if (A[index][0] == 0){
            for (int i = 0; i < A[0].size(); ++i) {
                if (A[index][i] == 0){
                    A[index][i] = 1;
                } else{
                    A[index][i] = 0;
                }
            }
        }
    }
    void changeColumn(vector<vector<int>>& A, int index){
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i][index] == 0){
                cnt0++;
            } else{
                cnt1++;
            }
        }
        if (cnt0 > cnt1){
            for (int i = 0; i < A.size(); ++i) {
                if (A[i][index] == 0){
                    A[i][index] = 1;
                } else{
                    A[i][index] = 0;
                }
            }
        }
    }
};

int main(){
    vector<vector<int>> A = {{0,0,1,1}, {1,0,1,0},{1,1,0,0}};
    Solution solution;
    int res = solution.matrixScore(A);
    cout << res << endl;
    return 0;
}