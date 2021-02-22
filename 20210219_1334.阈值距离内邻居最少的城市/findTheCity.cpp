//
// Created by ZD-Mac on 2021/2/19.
//

/*
 * 有 n 个城市，按从 0 到 n-1 编号。给你一个边数组 edges，其中 edges[i] = [fromi, toi, weighti] 代表 fromi 和 toi 两个城市之间的双向加权边，距离阈值是一个整数 distanceThreshold。

返回能通过某些路径到达其他城市数目最少、且路径距离 最大 为 distanceThreshold 的城市。如果有多个这样的城市，则返回编号最大的城市。

注意，连接城市 i 和 j 的路径的距离等于沿该路径的所有边的权重之和。

 

示例 1：



输入：n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
输出：3
解释：城市分布图如上。
每个城市阈值距离 distanceThreshold = 4 内的邻居城市分别是：
城市 0 -> [城市 1, 城市 2] 
城市 1 -> [城市 0, 城市 2, 城市 3] 
城市 2 -> [城市 0, 城市 1, 城市 3] 
城市 3 -> [城市 1, 城市 2] 
城市 0 和 3 在阈值距离 4 以内都有 2 个邻居城市，但是我们必须返回城市 3，因为它的编号最大。
示例 2：



输入：n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
输出：0
解释：城市分布图如上。 
每个城市阈值距离 distanceThreshold = 2 内的邻居城市分别是：
城市 0 -> [城市 1] 
城市 1 -> [城市 0, 城市 4] 
城市 2 -> [城市 3, 城市 4] 
城市 3 -> [城市 2, 城市 4]
城市 4 -> [城市 1, 城市 2, 城市 3] 
城市 0 在阈值距离 2 以内只有 1 个邻居城市。
 

提示：

2 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti, distanceThreshold <= 10^4
所有 (fromi, toi) 都是不同的。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        // 定义二维D向量，并初始化各个城市间距离为INT_MAX（无穷）
        vector<vector<int>> D(n, vector<int>(n, INT_MAX));
        // 根据edges[][]初始化D[][]
        for (auto &e : edges) {
            // 无向图两个城市间的两个方向距离相同
            D[e[0]][e[1]] = e[2];
            D[e[1]][e[0]] = e[2];
        }
        // Floyd算法
        for (int k = 0; k < n; k++) {
            // n个顶点依次作为插入点
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j || D[i][k] == INT_MAX || D[k][j] == INT_MAX) {
                        // 这些情况都不符合下一行的if条件，
                        // 单独拿出来只是为了防止两个INT_MAX相加导致溢出
                        continue;
                    }
                    D[i][j] = min(D[i][k] + D[k][j], D[i][j]);
                }
            }
        }
        // 选择出能到达其它城市最少的城市ret
        int ret;
        int minNum = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && D[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= minNum) {
                minNum = cnt;
                ret = i;
            }
        }
        return ret;
    }
};
