//
// Created by ZD-Mac on 2021/2/23.
//
/*
 * 二叉树上有 n 个节点，按从 0 到 n - 1 编号，其中节点 i 的两个子节点分别是 leftChild[i] 和 rightChild[i]。

只有 所有 节点能够形成且 只 形成 一颗 有效的二叉树时，返回 true；否则返回 false。

如果节点 i 没有左子节点，那么 leftChild[i] 就等于 -1。右子节点也符合该规则。

注意：节点没有值，本问题中仅仅使用节点编号。

 

示例 1：



输入：n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
输出：true
示例 2：



输入：n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
输出：false
示例 3：



输入：n = 2, leftChild = [1,0], rightChild = [-1,-1]
输出：false
示例 4：



输入：n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
输出：false
 

提示：

1 <= n <= 10^4
leftChild.length == rightChild.length == n
-1 <= leftChild[i], rightChild[i] <= n - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-tree-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>

using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indeg(n);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                ++indeg[leftChild[i]];
            }
            if (rightChild[i] != -1) {
                ++indeg[rightChild[i]];
            }
        }

        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (!indeg[i]) {
                root = i;
                break;
            }
        }
        if (root == -1) {
            return false;
        }

        unordered_set<int> seen;
        queue<int> q;
        seen.insert(root);
        q.push(root);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (leftChild[u] != -1) {
                if (seen.count(leftChild[u])) {
                    return false;
                }
                seen.insert(leftChild[u]);
                q.push(leftChild[u]);
            }
            if (rightChild[u] != -1) {
                if (seen.count(rightChild[u])) {
                    return false;
                }
                seen.insert(rightChild[u]);
                q.push(rightChild[u]);
            }
        }

        return seen.size() == n;
    }
};

