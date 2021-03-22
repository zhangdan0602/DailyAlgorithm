//
// Created by ZD-Mac on 2021/3/20.
//

/*
 * 时间限制： 1.0 秒

空间限制： 512 MB

题目描述
有一个图，一共有 𝑚 条边，节点编号从 0 到 𝑚。现在只知道 𝑚 条边和一个整数 𝑘。

如果该图构成一棵树，则尝试找出一个节点满足：以该节点为根，所有节点的儿子数都不超过 𝑘。

如果给定的 𝑚 条边无法构成一棵树，则输出 It's not a tree!

如果不存在这样的节点作为根，则输出 No such a node!

否则输出一个节点的编号，表示以该节点为根，所有节点的儿子数都不超过 𝑘，如果同时存在多个节点满足条件，则输出编号最小的节点编号。

输入格式
从标准输入读入数据。

输入的第一行包含两个正整数 𝑚 和 𝑘，保证 𝑚≤105，𝑘≤105。

输入的接下来 𝑚 行包含两个整数 𝑎,𝑏，表示 𝑎 和 𝑏 相连, 保证 0≤𝑎,𝑏≤𝑚。

输出格式
输出到标准输出。

输出一个字符串或者一个整数表示对应的答案。

样例1输入
5 2
0 1
0 2
0 3
1 4
1 5
样例1输出
2
样例2输入
5 2
0 1
0 2
0 3
1 2
1 5
样例2输出
It's not a tree!
子任务
子任务一(20分)：保证有解，且答案为 0 或 1。

子任务二(20分)：保证图构成一棵树。

子任务三(15分): 保证 𝑘=1。

子任务四(20分): 保证有解。

子任务五(25分)：无特殊情况。
 */
#include <vector>
#include <iostream>

using namespace std;

int find(vector<int> &parent, int index) {
    if (parent[index] != index) {
        parent[index] = find(parent, parent[index]);
    }
    return parent[index];
}

void Union(vector<int> &parent, int index1, int index2) {
    parent[find(parent, index1)] = find(parent, index2);
}


int main() {
    int m, k;
    cin >> m >> k;
    vector<vector<int>> graph(m);

    int nodesCount = graph.size();
    vector<int> parent(nodesCount + 1);
    for (int i = 1; i <= nodesCount; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if (find(parent, a) != find(parent, b)) {
            Union(parent, a, b);
        } else {
            cout << "It's not a tree!" << endl;
            return 0;
        }
    }
    int cnt0 = 0;
    for (int i = 0; i < m; ++i) {
        if (graph[i].size() == 0) {
            cnt0++;
        }
    }
    if (cnt0 == graph.size()) {
        cout << "No such a node!" << endl;
        return 0;
    }
    int idx = -1;
    for (int i = 0; i < m; ++i) {
        if (graph[i].size() > k + 1) {
            cout << "No such a node!" << endl;
            return 0;
        }
        if (graph[i].size() <= k && idx == -1) {
            idx = i;
        }
    }
    cout << idx << endl;
    return 0;
}