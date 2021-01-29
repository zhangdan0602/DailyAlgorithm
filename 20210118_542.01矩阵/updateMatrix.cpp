//
// Created by ZD-Mac on 2021-01-18.
//

/*
 * 给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

 

示例 1：

输入：
[[0,0,0],
 [0,1,0],
 [0,0,0]]

输出：
[[0,0,0],
 [0,1,0],
 [0,0,0]]
示例 2：

输入：
[[0,0,0],
 [0,1,0],
 [1,1,1]]

输出：
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

提示：

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/01-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0},
                                       {1,  0},
                                       {0,  -1},
                                       {0,  1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> que;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    que.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }
        while (!que.empty()) {
            auto[x, y] = que.front();
            que.pop();
            for (int d = 0; d < 4; ++d) {
                int dx = dirs[d][0] + x;
                int dy = dirs[d][1] + y;
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && !seen[dx][dy]) {
                    dist[dx][dy] = dist[x][y] + 1;
                    que.emplace(dx, dy);
                    seen[dx][dy] = 1;
                }
            }
        }
        return dist;
    }
};
