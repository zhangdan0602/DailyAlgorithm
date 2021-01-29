//
// Created by ZD-Mac on 2021-01-17.
//

/*
 * 给定一组 N 人（编号为 1, 2, ..., N）， 我们想把每个人分进任意大小的两组。

每个人都可能不喜欢其他人，那么他们不应该属于同一组。

形式上，如果 dislikes[i] = [a, b]，表示不允许将编号为 a 和 b 的人归入同一组。

当可以用这种方法将所有人分进两组时，返回 true；否则返回 false。

 

示例 1：

输入：N = 4, dislikes = [[1,2],[1,3],[2,4]]
输出：true
解释：group1 [1,4], group2 [2,3]
示例 2：

输入：N = 3, dislikes = [[1,2],[1,3],[2,3]]
输出：false
示例 3：

输入：N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
输出：false
 

提示：

1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
对于 dislikes[i] == dislikes[j] 不存在 i != j

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/possible-bipartition
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> group;
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        for (auto v : dislikes) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        for (int i = 1; i <= N; ++i) {
            if (group.find(i) == group.end() && !dfs(i, 0)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int node, int id) {
        if (group.find(node) != group.end())
            return group[node] == id;
        group[node] = id;
        for (auto n : graph[node]) {
            if (!dfs(n, id ^ 1)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> dislikes = {{1, 2},
                                    {1, 3},
                                    {2, 3}};
    bool res = solution.possibleBipartition(3, dislikes);
    cout << res << endl;
    return 0;
}


