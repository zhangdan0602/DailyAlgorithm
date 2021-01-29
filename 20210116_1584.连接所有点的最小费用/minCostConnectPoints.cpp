//
// Created by ZD-Mac on 2021-01-16.
//

/*
 * 给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。

连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。

请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。

 

示例 1：



输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
输出：20
解释：

我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
注意到任意两个点之间只有唯一一条路径互相到达。
示例 2：

输入：points = [[3,12],[-2,5],[-4,1]]
输出：18
示例 3：

输入：points = [[0,0],[1,1],[1,0],[-1,1]]
输出：4
示例 4：

输入：points = [[-1000000,-1000000],[1000000,1000000]]
输出：4000000
示例 5：

输入：points = [[0,0]]
输出：0
 

提示：

1 <= points.length <= 1000
-106 <= xi, yi <= 106
所有点 (xi, yi) 两两不同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-cost-to-connect-all-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> parent;
    int part = 0;

public:
    struct Edge {
        int a, b, w;

        bool operator<(const Edge &e) const {
            return w < e.w;
        }
    };

    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();
        if (n <= 1)
            return 0;
        vector<Edge> connections;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                connections.push_back({i, j, abs(points[i][0] - points[j][0] + abs(points[i][1] - points[j][1]))});
            }
        }
        return mininumCost(n, connections);
    }

    int mininumCost(int n, vector<Edge> &connections) {
        int res = 0;
        part = n;
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        sort(connections.begin(), connections.end());
        for (Edge &e:connections) {
            int a = find(e.a);
            int b = find(e.b);
            if (a != b) {
                Union(e.a, e.b);
                res += e.w;
            }
            if (part == 1)
                return res;
        }
        return -1;
    }

    int find(int index) {
        if (index == parent[index])
            return index;
        parent[index] = find(parent[index]);
        return parent[index];
    }

    void Union(int index1, int index2) {
        int p1 = find(index1);
        int p2 = find(index2);
        if (p1 == p2)
            return;
        parent[p1] = p2;
        part--;
    }
};

/*
 class Solution {
private:
    vector<int> parent;
    int part = 0;
public:
    struct Edge{
        int a, b, w;
        bool operator<(const Edge& e) const {
            return w < e.w;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 1) return 0;
        //connections每一行是两个顶点和权重
        vector<Edge> connections;
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                connections.push_back({i, j,
                                       abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
            }
        }
        return minimumCost(n, connections);
    }

    int minimumCost(int n, vector<Edge>& connections) {
        part = n;
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        //把所有边按权值进行排序
        sort(connections.begin(), connections.end());
        int res = 0;
        for (Edge& conn : connections) {
            int pa = find(conn.a);
            int pb = find(conn.b);
            if (pa != pb) {
                uni(conn.a, conn.b);
                res += conn.w;
            }
            if (part == 1)
                return res;
        }
        return -1;
    }
    int find(int a) {
        if (parent[a] == a)
            return a;
        parent[a] = find(parent[a]);
        return parent[a];
    }
    void uni(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return;
        parent[pa] = pb;
        part --;
    }
};
 */

int main() {
    Solution solution;
    vector<vector<int>> points = {{0, 0},
                                  {2, 2},
                                  {3, 10},
                                  {5, 2},
                                  {7, 0}};
    int res = solution.minCostConnectPoints(points);
    cout << res << endl;
    return 0;
}




