//
// Created by ZD-Mac on 2021-01-09.
//

/*
 * 编写一个程序，通过填充空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sudoku-solver
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 提示：

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。
 */
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (auto i = 0; i < board.size(); ++i) {
            for (auto j = 0; j < board[i].size(); ++j) {
                char c = board[i][j];
                if (c == '.') {
                    mSpace.emplace_back(i, j);
                }
                else {
                    mRow[i][c - '1'] = true;
                    mCol[j][c - '1'] = true;
                    mSquared[i / 3 * 3 + j / 3][c - '1'] = true;
                }
            }
        }
        Dfs(board, 0);
    }

    bool Dfs(vector<vector<char>>& board, int index) {
        if (index == mSpace.size()) {
            return true;
        }

        auto row = mSpace[index].first;
        auto col = mSpace[index].second;
        for (auto c = '1'; c <= '9'; ++c) {
            auto num = c - '1';
            if (!mRow[row][num] && !mCol[col][num] && !mSquared[row / 3 * 3 + col / 3][num]) {
                board[row][col] = c;
                mRow[row][num] = true;
                mCol[col][num] = true;
                mSquared[row / 3 * 3 + col / 3][num] = true;
                if (Dfs(board, index + 1)) {
                    return true;
                }
                mRow[row][num] = false;
                mCol[col][num] = false;
                mSquared[row / 3 * 3 + col / 3][num] = false;
            }
        }
        return false;
    }

private:
    bool mCol[9][9];
    bool mRow[9][9];
    bool mSquared[9][9];
    vector<pair<int, int>> mSpace;
};