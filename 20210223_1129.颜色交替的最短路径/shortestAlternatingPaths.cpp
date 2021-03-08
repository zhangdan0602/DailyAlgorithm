//
// Created by ZD-Mac on 2021/2/23.
//

/*
 * 在一个有向图中，节点分别标记为0, 1, ..., n-1。这个图中的每条边不是红色就是蓝色，且存在自环或平行边。

red_edges中的每一个[i, j]对表示从节点 i 到节点 j 的红色有向边。
 类似地，blue_edges中的每一个[i, j]对表示从节点 i 到节点 j 的蓝色有向边。

返回长度为 n 的数组answer，其中answer[X]是从节点0到节点X的红色边和蓝色边交替出现的最短路径的长度。
 如果不存在这样的路径，那么 answer[x] = -1。



示例 1：

输入：n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
输出：[0,1,-1]
示例 2：

输入：n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
输出：[0,1,-1]
示例 3：

输入：n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
输出：[0,-1,-1]
示例 4：

输入：n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
输出：[0,1,2]
示例 5：

输入：n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
输出：[0,1,1]


提示：

1 <= n <= 100
red_edges.length <= 400
blue_edges.length <= 400
red_edges[i].length == blue_edges[i].length == 2
0 <= red_edges[i][j], blue_edges[i][j] < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-path-with-alternating-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges) {
        vector<set<int>> red_path(n);
        vector<set<int>> blue_path(n);
        vector<pair<int, int>> dist(n);
        dist[0].first = 0;
        dist[0].second = 0;
        for (int i = 1; i < n; ++i) {
            dist[i].first = -1;
            dist[i].second = -1;
        }
        queue<int> now_red;
        queue<int> now_blue;
        vector<int> res(n);
        int step = 0;
        now_red.push(0);
        now_blue.push(0);
        for (auto &path:red_edges) {
            red_path[path[0]].insert(path[1]);
        }
        for (auto &path:blue_edges) {
            blue_path[path[0]].insert(path[1]);
        }
        while (!now_red.empty() && !now_blue.empty()) {
            queue<int> new_red, new_blue;
            step += 1;
            if (!now_red.empty()) {
                while (!now_red.empty()) {
                    int point = now_red.front();
                    now_red.pop();
                    for (auto next_point:blue_path[point]) {
                        if (dist[next_point].second == -1) {
                            new_blue.push(next_point);
                            dist[next_point].second = step;
                        }
                    }
                }
            }
            if (!now_blue.empty()) {
                while (!now_blue.empty()) {
                    int point = now_blue.front();
                    now_blue.pop();
                    for (auto next_point:red_path[point]) {
                        if (dist[next_point].first == -1) {
                            new_red.push(next_point);
                            dist[next_point].first = step;
                        }
                    }
                }
            }
            now_red = new_red;
            now_blue = new_blue;
        }
        for (int i = 0; i < n; ++i) {
            if (dist[i].first == -1 && dist[i].second == -1) {
                res[i] = -1;
            } else if (dist[i].first != -1 && dist[i].second != -1) {
                res[i] = min(dist[i].first, dist[i].second);
            } else {
                res[i] = max(dist[i].first, dist[i].second);
            }
        }
        return res;
    }
};
/*
 * public int[] shortestAlternatingPaths(int n, int[][] red_edges, int[][] blue_edges) {
        //准备工作
        List<Set<Integer>> red_path = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            red_path.add(new HashSet<>());
        }
        for (int index = 0; index < red_edges.length; index++) {
            red_path.get(red_edges[index][0]).add(red_edges[index][1]);
        }
        List<Set<Integer>> blue_path = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            blue_path.add(new HashSet<>());
        }
        for (int index = 0; index < blue_edges.length; index++) {
            blue_path.get(blue_edges[index][0]).add(blue_edges[index][1]);
        }
        int[][] dist = new int[n][2];
        dist[0][0] = 0;
        dist[0][1] = 0;
        for (int i = 1; i < n; i++) {
            dist[i][0] = -1;
            dist[i][1] = -1;
        }
        int step = 0;
        Queue<Integer> now_red = new LinkedList<>();
        Queue<Integer> now_blue = new LinkedList<>();
        now_red.add(0);
        now_blue.add(0);
        //# step 1 找到分别以红边开始和以蓝边开始的两条最短路径
        while (!now_red.isEmpty() || !now_blue.isEmpty()) {
            Queue<Integer> new_red = new LinkedList<>();
            Queue<Integer> new_blue = new LinkedList<>();
            step++;
            if (!now_red.isEmpty()) {
                while (!now_red.isEmpty()) {
                    Set<Integer> tmpSet = blue_path.get(now_red.poll());
                    for (int ele : tmpSet) {
                        if (dist[ele][1] == -1) {
                            new_blue.add(ele);
                            dist[ele][1] = step;
                        }
                    }
                }
            }
            if (!now_blue.isEmpty()) {
                while (!now_blue.isEmpty()) {
                    Set<Integer> tmpSet = red_path.get(now_blue.poll());
                    for (int ele : tmpSet) {
                        if (dist[ele][0] == -1) {
                            new_red.add(ele);
                            dist[ele][0] = step;
                        }
                    }
                }
            }
            now_red = new_red;
            now_blue = new_blue;
        }
        //# step 2 在这两条最短路径中选择小的，merge成我们的答案
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            if (dist[i][0] == -1 && dist[i][1] == -1) {
                ret[i] = -1;
            } else if (dist[i][0] != -1 && dist[i][1] != -1) {
                ret[i] = Math.min(dist[i][0], dist[i][1]);
            } else {
                ret[i] = Math.max(dist[i][0], dist[i][1]);
            }
        }
        return ret;
    }
    */