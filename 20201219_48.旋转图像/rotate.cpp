//
// Created by ZD-Mac on 2020-12-19.
//

/*
 * 给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        auto matrix_new = matrix;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                matrix_new[col][n - row - 1] = matrix[row][col];
            }
        }
        matrix = matrix_new;
    }

    void rotate1(vector<vector<int>>& matrix){
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < k; ++i) {
                swap(matrix[k][i], matrix[i][k]);
            }
        }
    }
};

int main(){
    Solution solution;
    vector<vector<int>> matrix(4, vector<int>(4));
    matrix[0] = {5, 1, 9, 11};
    matrix[1] = {2, 4, 8, 10};
    matrix[2] = {13, 3, 6, 7};
    matrix[3] = {15, 14, 12, 16};
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    solution.rotate1(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
