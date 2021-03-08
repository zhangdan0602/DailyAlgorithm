//
// Created by ZD-Mac on 2021/2/27.
//

/*
 * 给你一个大小为m x n的整数矩阵isWater，它代表了一个由 陆地和 水域单元格组成的地图。

如果isWater[i][j] == 0，格子(i, j)是一个 陆地格子。
如果isWater[i][j] == 1，格子(i, j)是一个 水域格子。
你需要按照如下规则给每个单元格安排高度：

每个格子的高度都必须是非负的。
如果一个格子是是 水域，那么它的高度必须为 0。
任意相邻的格子高度差 至多为 1。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。（也就是说它们有一条公共边）
找到一种安排高度的方案，使得矩阵中的最高高度值最大。

请你返回一个大小为m x n的整数矩阵 height，其中 height[i][j]是格子 (i, j)的高度。如果有多种解法，请返回任意一个。



示例 1：



输入：isWater = [[0,1],[0,0]]
输出：[[1,0],[2,1]]
解释：上图展示了给各个格子安排的高度。
蓝色格子是水域格，绿色格子是陆地格。
示例 2：



输入：isWater = [[0,0,1],[1,0,0],[0,0,0]]
输出：[[1,1,0],[0,1,1],[1,2,2]]
解释：所有安排方案中，最高可行高度为 2 。
任意安排方案中，只要最高高度为 2 且符合上述规则的，都为可行方案。


提示：

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j]要么是0，要么是1。
至少有 1个水域格子。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/map-of-highest-peak
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int R = isWater.size(),     C = isWater[0].size();
        vector<vector<int>> res(R, vector<int>(C, 0));
        queue<tuple<int, int>> que;                 //有tuple谁还用pair<>
        for (int r = 0; r < R; r ++)
            for (int c = 0; c < C; c ++)
                if (isWater[r][c] == 1)
                    que.push(make_tuple(r,c));      //从水出发,高度为0的点们
        while (que.size())                          //多源BFS + 记忆化
        {
            auto [r,c] = que.front();   que.pop();
            for (auto [nr, nc] : vector<tuple<int,int>>{{r-1,c},{r,c+1},{r+1,c},{r,c-1}})
            {
                if (0 <= nr && nr < R && 0 <= nc && nc < C && isWater[nr][nc] == 0)
                {
                    res[nr][nc] = res[r][c] + 1;
                    isWater[nr][nc] = 1;            //天然的记忆化visited数组  染色法 的思想
                    que.push(make_tuple(nr,nc));
                }
            }
        }
        return res;
    }
};