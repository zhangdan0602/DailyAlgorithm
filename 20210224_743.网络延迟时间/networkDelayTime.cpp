//
// Created by ZD-Mac on 2021/2/24.
//

/*
 * 有 n 个网络节点，标记为 1 到 n。

给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。

现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。

 

示例 1：



输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
输出：2
示例 2：

输入：times = [[1,2,1]], n = 2, k = 1
输出：1
示例 3：

输入：times = [[1,2,1]], n = 2, k = 2
输出：-1
 

提示：

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
所有 (ui, vi) 对都 互不相同（即，不含重复边）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/network-delay-time
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        //朴素dijkstra
        const int INF = 0x3f3f3f3f;
        vector<vector<int>> g(n + 1, vector<int>(n + 1, INF));
        for (auto &v: times) {
            g[v[0]][v[1]] = v[2];
        }
        vector<int> dist(n + 1, INF); // 距离起始点的最短距离
        vector<bool> st(n + 1, false); // 是否已经得到最优解

        dist[K] = 0; // 起始点
        for (int i = 0; i < n - 1; i++) {
            int t = -1;
            for (int j = 1; j <= n; j++) { // 在还未确定最短路的点中，寻找到起始点距离最小的点 的点
                if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }

            st[t] = true; // t号点的最短路已经确定

            for (int j = 1; j <= n; j++) { // 用t更新其他点的距离
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INF ? -1 : ans;
    }
};