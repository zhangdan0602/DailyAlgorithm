//
// Created by ZD-Mac on 2021-01-17.
//
/*
 * 给定一个二叉树，在树的最后一行找到最左边的值。

示例 1:

输入:

    2
   / \
  1   3

输出:
1
 

示例 2:

输入:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

输出:
7
 

注意: 您可以假设树（即给定的根节点）不为 NULL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-bottom-left-tree-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(0), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> que;
        if (root != NULL)
            que.push(root);
        int res = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                if (i == 0)
                    res = node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    TreeNode *treeNode = new TreeNode(1);
    treeNode->left = new TreeNode(2);
    treeNode->right = new TreeNode(3);
    int res = solution.findBottomLeftValue(treeNode);
    cout << res << endl;
    return 0;
}