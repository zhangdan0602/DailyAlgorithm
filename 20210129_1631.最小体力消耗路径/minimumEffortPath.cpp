//
// Created by ZD-Mac on 2021-01-28.
//

/*
 * 你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

请你返回从左上角走到右下角的最小 体力消耗值 。

 

示例 1：



输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
输出：2
解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
示例 2：



输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
输出：1
解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
示例 3：


输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
输出：0
解释：上图所示路径不需要消耗任何体力。
 

提示：

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-with-minimum-effort
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <numeric>

using namespace std;

class UF {
public:
    vector<int> fa;
    vector<int> sz;
    int n;
    int comp_cnt;

public:
    UF(int _n): n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int findset(int x) {
        return fa[x] == x ? x : fa[x] = findset(fa[x]);
    }

    void unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return;
        }
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
    }

    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

struct Edge {
    int x, y, z;
    Edge(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
    bool operator< (const Edge& that) const {
        return z < that.z;
    }
};

class Solution {
public:
    //并查集
    int minimumEffortPath(vector<vector<int>> &heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<Edge> edges;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int id = i * n + j;
                if (i > 0) {
                    edges.emplace_back(id - n, id, abs(heights[i][j] - heights[i - 1][j]));
                }
                if (j > 0) {
                    edges.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
                }
            }
        }

        sort(edges.begin(), edges.end());
        UF uf(m * n);
        for (const auto& edge: edges) {
            uf.unite(edge.x, edge.y);
            if (uf.connected(0, m * n - 1)) {
                return edge.z;
            }
        }
        return 0;
    }
};

// 最短路径 Dijkstra
//struct Dist {
//    int x, y, z;
//    Dist(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
//    bool operator< (const Dist& that) const {
//        return z > that.z;
//    }
//};
//
//class Solution {
//private:
//    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//
//public:
//    int minimumEffortPath(vector<vector<int>>& heights) {
//        int m = heights.size();
//        int n = heights[0].size();
//
//        priority_queue<Dist> q;
//        vector<int> seen(m * n);
//        vector<int> dist(m * n, INT_MAX);
//        q.emplace(0, 0, 0);
//        dist[0] = 0;
//        while (!q.empty()) {
//            auto [x, y, z] = q.top();
//            q.pop();
//            if (seen[x * n + y]) {
//                continue;
//            }
//            seen[x * n + y] = 1;
//            dist[x * n + y] = z;
//            for (int i = 0; i < 4; ++i) {
//                int nx = x + dirs[i][0];
//                int ny = y + dirs[i][1];
//                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny]) {
//                    q.emplace(nx, ny, max(z, abs(heights[x][y] - heights[nx][ny])));
//                }
//            }
//        }
//        return dist[m * n - 1];
//    }
//};

