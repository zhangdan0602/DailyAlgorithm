//
// Created by ZD-Mac on 2021-01-18.
//

/*
 * 给你一个 m x n 的网格 grid。网格里的每个单元都代表一条街道。grid[i][j] 的街道可以是：

1 表示连接左单元格和右单元格的街道。
2 表示连接上单元格和下单元格的街道。
3 表示连接左单元格和下单元格的街道。
4 表示连接右单元格和下单元格的街道。
5 表示连接左单元格和上单元格的街道。
6 表示连接右单元格和上单元格的街道。


你最开始从左上角的单元格 (0,0) 开始出发，网格中的「有效路径」是指从左上方的单元格 (0,0) 开始、一直到右下方的 (m-1,n-1) 结束的路径。该路径必须只沿着街道走。

注意：你 不能 变更街道。

如果网格中存在有效的路径，则返回 true，否则返回 false 。

 

示例 1：



输入：grid = [[2,4,3],[6,5,2]]
输出：true
解释：如图所示，你可以从 (0, 0) 开始，访问网格中的所有单元格并到达 (m - 1, n - 1) 。
示例 2：



输入：grid = [[1,2,1],[1,2,1]]
输出：false
解释：如图所示，单元格 (0, 0) 上的街道没有与任何其他单元格上的街道相连，你只会停在 (0, 0) 处。
示例 3：

输入：grid = [[1,1,2]]
输出：false
解释：你会停在 (0, 1)，而且无法到达 (0, 2) 。
示例 4：

输入：grid = [[1,1,1,1,1,1,3]]
输出：true
示例 5：

输入：grid = [[2],[2],[2],[2],[2],[2],[6]]
输出：true
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
1 <= grid[i][j] <= 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-there-is-a-valid-path-in-a-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static constexpr int MAX_N = 300 * 300 + 5;

    struct DisjointSet {
        int f[MAX_N];

        DisjointSet() {
            for (int i = 0; i < MAX_N; ++i) {
                f[i] = i;
            }
        }

        int find(int x) {
            return x == f[x] ? x : f[x] = find(f[x]);
        }

        void merge(int x, int y) {
            f[find(x)] = find(y);
        }
    } ds;

    bool hasValidPath(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        auto getId = [&](int x, int y) {
            return x * n + y;
        };
        auto detectL = [&](int x, int y) {
            if (y - 1 >= 0 && (grid[x][y - 1] == 4 || grid[x][y - 1] == 6 || grid[x][y - 1] == 1)) {
                ds.merge(getId(x, y), getId(x, y - 1));
            }
        };
        auto detectR = [&](int x, int y) {
            if (y + 1 < n && (grid[x][y + 1] == 3 || grid[x][y + 1] == 5 || grid[x][y + 1] == 1)) {
                ds.merge(getId(x, y), getId(x, y + 1));
            }
        };
        auto detectU = [&](int x, int y) {
            if (x - 1 >= 0 && (grid[x - 1][y] == 3 || grid[x - 1][y] == 4 || grid[x - 1][y] == 2)) {
                ds.merge(getId(x, y), getId(x - 1, y));
            }
        };
        auto detectD = [&](int x, int y) {
            if (x + 1 < m && (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 || grid[x + 1][y] == 2)) {
                ds.merge(getId(x, y), getId(x + 1, y));
            }
        };

        auto handler = [&](int x, int y) {
            switch (grid[x][y]) {
                case 1: {
                    detectL(x, y);
                    detectR(x, y);
                }
                    break;
                case 2: {
                    detectU(x, y);
                    detectD(x, y);
                }
                    break;
                case 3: {
                    detectL(x, y);
                    detectD(x, y);
                }
                    break;
                case 4: {
                    detectR(x, y);
                    detectD(x, y);
                }
                    break;
                case 5: {
                    detectL(x, y);
                    detectU(x, y);
                }
                    break;
                case 6: {
                    detectR(x, y);
                    detectU(x, y);
                }
                    break;
            }
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                handler(i, j);
            }
        }
        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{1, 2, 1},
                                {1, 2, 1}};
    bool res = solution.hasValidPath(grid);
    cout << res << endl;
    return 0;
}