//
// Created by zd on 2020/10/9.
//
/*
 * 给你二叉树的根节点 root 和一个整数 distance 。
如果二叉树中两个 叶 节点之间的 最短路径长度 小于或者等于 distance ，那它们就可以构成一组 好叶子节点对 。
返回树中 好叶子节点对的数量 。

示例 1：
输入：root = [1,2,3,null,4], distance = 3
输出：1
解释：树的叶节点是 3 和 4 ，它们之间的最短路径的长度是 3 。这是唯一的好叶子节点对。

示例 2：
输入：root = [1,2,3,4,5,6,7], distance = 3
输出：2
解释：好叶子节点对为 [4,5] 和 [6,7] ，最短路径长度都是 2 。但是叶子节点对 [4,6] 不满足要求，因为它们之间的最短路径长度为 4 。

示例 3：
输入：root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
输出：1
解释：唯一的好叶子节点对是 [2,5] 。

示例 4：
输入：root = [100], distance = 1
输出：0

示例 5：
输入：root = [1,1,1], distance = 2
输出：1


提示：
    tree 的节点数在 [1, 2^10] 范围内。
    每个节点的值都在 [1, 100] 之间。
    1 <= distance <= 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-good-leaf-nodes-pairs
 */
/*
 * 对于二叉树的任意两个不同的叶子节点 AAA、BBB，一个重要的性质是：它们之间有且仅有一条最短路径。设两个叶子节点的最近公共祖先为 PPP，则最短路径的长度，等于 AAA 到 PPP 的距离，加上 BBB 到 PPP 的距离。

于是，我们遍历所有非叶子节点 PPP，找到以 PPP 为最近公共祖先的所有叶子节点对，并根据上面的等式，计算每一对之间的距离，并统计距离不超过 distance\textit{distance}distance 的节点对数目，就能够得到最终的答案。

那么怎么计算每个叶子节点对之间的距离呢？关键是要知道：以 PPP 为根节点的子树中的所有叶子节点，它们与 PPP 之间的距离。于是，对于任意的节点 PPP，我们先通过递归的方式，统计叶子节点与 PPP 的左孩子 left\textit{left}left、右孩子 right\textit{right}right 之间的距离；这样，两个以 PPP 为最近公共祖先的叶子节点 AAA、BBB，其中一个（例如 AAA）在以 left\textit{left}left 为根的子树中，另一个（例如 BBB）在以 right\textit{right}right 为根的子树中。AAA 与 BBB 之间的距离，就等于 AAA 与 left\textit{left}left 之间的距离，加上 BBB 与 right\textit{right}right 之间的距离，再加上 222。

由于本题中约束 distance≤10\textit{distance} \le 10distance≤10，因此对于每个非叶子节点 PPP，只需开辟长度为 distance+1\textit{distance}+1distance+1 的数组 depths\textit{depths}depths，其中 depths[i]\textit{depths}[i]depths[i] 表示与 PPP 之间的距离为 iii 的叶子节点数目。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/number-of-good-leaf-nodes-pairs/solution/hao-xie-zi-jie-dian-dui-de-shu-liang-by-leetcode-s/
来源：力扣（LeetCode）
 */
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution{
public:
    // 对于 dfs(root,distance)，同时返回：
    // 1）每个叶子节点与 root 之间的距离
    // 2) 以 root 为根节点的子树中好叶子节点对的数量
    pair<vector<int>, int> dfs(TreeNode* root, int distance) {
        vector<int> depths(distance + 1, 0);
        bool isLeaf = (!root->left && !root->right);
        if (isLeaf) {
            depths[0] = 1;
            return make_pair(depths, 0);
        }

        vector<int> leftDepths(distance + 1, 0), rightDepths(distance + 1, 0);
        int leftCount = 0, rightCount = 0;
        if (root->left) {
            tie(leftDepths, leftCount) = dfs(root->left, distance);
        }
        if (root->right) {
            tie(rightDepths, rightCount) = dfs(root->right, distance);
        }

        for (int i = 0; i < distance; i++) {
            depths[i + 1] += leftDepths[i];
            depths[i + 1] += rightDepths[i];
        }

        int cnt = 0;
        for (int i = 0; i <= distance; i++) {
            for (int j = 0; j + i + 2 <= distance; j++) {
                cnt += (leftDepths[i] * rightDepths[j]);
            }
        }
        return make_pair(depths, cnt + leftCount + rightCount);
    }

    int countPairs(TreeNode* root, int distance) {
        auto [depths, ret] = dfs(root, distance);
        return ret;
    }
};

int main(){
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    auto num = solution.countPairs(root, 0);
    cout << num << endl;
}

