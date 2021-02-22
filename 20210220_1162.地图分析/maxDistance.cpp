//
// Created by ZD-Mac on 2021/2/20.
//

/*
 * 你现在手里有一份大小为 N x N 的 网格 grid，上面的每个 单元格 都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的。

我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - x1| + |y0 - y1| 。

如果网格上只有陆地或者海洋，请返回 -1。

 

示例 1：



输入：[[1,0,1],[0,0,0],[1,0,1]]
输出：2
解释：
海洋单元格 (1, 1) 和所有陆地单元格之间的距离都达到最大，最大距离为 2。
示例 2：



输入：[[1,0,0],[0,0,0],[0,0,0]]
输出：4
解释：
海洋单元格 (2, 2) 和所有陆地单元格之间的距离都达到最大，最大距离为 4。
 

提示：

1 <= grid.length == grid[0].length <= 100
grid[i][j] 不是 0 就是 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>> &grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        if (q.empty() || q.size() == n * n) {
            return -1;
        }
        int dis = -1;
        while (!q.empty()) {
            dis++;
            int m = q.size();
            for (int i = 0; i < m; ++i) {
                pair<int, int> p = q.front();
                int row = p.first;
                int col = p.second;
                q.pop();
                if (row - 1 >= 0 && grid[row - 1][col] == 0) {
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                }
                if (row + 1 < n && grid[row + 1][col] == 0) {
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                }
                if (col - 1 >= 0 && grid[row][col - 1] == 0) {
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                }
                if (col + 1 < n && grid[row][col + 1] == 0) {
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                }
            }
        }
        return dis;
    }
};