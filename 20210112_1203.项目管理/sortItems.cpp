//
// Created by ZD-Mac on 2021-01-12.
//

/*
 * 公司共有 n 个项目和  m 个小组，每个项目要不无人接手，要不就由 m 个小组之一负责。

group[i] 表示第 i 个项目所属的小组，如果这个项目目前无人接手，那么 group[i] 就等于 -1。（项目和小组都是从零开始编号的）小组可能存在没有接手任何项目的情况。

请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：

同一小组的项目，排序后在列表中彼此相邻。
项目之间存在一定的依赖关系，我们用一个列表 beforeItems 来表示，其中 beforeItems[i] 表示在进行第 i 个项目前（位于第 i 个项目左侧）应该完成的所有项目。
如果存在多个解决方案，只需要返回其中任意一个即可。如果没有合适的解决方案，就请返回一个 空列表 。

 输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
输出：[6,3,4,1,5,2,0,7]
示例 2：

输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
输出：[]
解释：与示例 1 大致相同，但是在排序后的列表中，4 必须放在 6 的前面。
 

提示：

1 <= m <= n <= 3 * 104
group.length == beforeItems.length == n
-1 <= group[i] <= m - 1
0 <= beforeItems[i].length <= n - 1
0 <= beforeItems[i][j] <= n - 1
i != beforeItems[i][j]
beforeItems[i] 不含重复元素

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topSort(vector<int>& deg, vector<vector<int>>& graph, vector<int>& items) {
        queue<int> Q;
        for (auto& item: items) {
            if (deg[item] == 0) {
                Q.push(item);
            }
        }
        vector<int> res;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            res.emplace_back(u);
            for (auto& v: graph[u]) {
                if (--deg[v] == 0) {
                    Q.push(v);
                }
            }
        }
        return res.size() == items.size() ? res : vector<int>{};
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> groupItem(n + m);

        // 组间和组内依赖图
        vector<vector<int>> groupGraph(n + m);
        vector<vector<int>> itemGraph(n);

        // 组间和组内入度数组
        vector<int> groupDegree(n + m, 0);
        vector<int> itemDegree(n, 0);

        vector<int> id;
        for (int i = 0; i < n + m; ++i) {
            id.emplace_back(i);
        }

        int leftId = m;
        // 给未分配的 item 分配一个 groupId
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = leftId;
                leftId += 1;
            }
            groupItem[group[i]].emplace_back(i);
        }
        // 依赖关系建图
        for (int i = 0; i < n; ++i) {
            int curGroupId = group[i];
            for (auto& item: beforeItems[i]) {
                int beforeGroupId = group[item];
                if (beforeGroupId == curGroupId) {
                    itemDegree[i] += 1;
                    itemGraph[item].emplace_back(i);
                } else {
                    groupDegree[curGroupId] += 1;
                    groupGraph[beforeGroupId].emplace_back(curGroupId);
                }
            }
        }

        // 组间拓扑关系排序
        vector<int> groupTopSort = topSort(groupDegree, groupGraph, id);
        if (groupTopSort.size() == 0) {
            return vector<int>{};
        }
        vector<int> ans;
        // 组内拓扑关系排序
        for (auto& curGroupId: groupTopSort) {
            int size = groupItem[curGroupId].size();
            if (size == 0) {
                continue;
            }
            vector<int> res = topSort(itemDegree, itemGraph, groupItem[curGroupId]);
            if (res.size() == 0) {
                return vector<int>{};
            }
            for (auto& item: res) {
                ans.emplace_back(item);
            }
        }
        return ans;
    }
};
