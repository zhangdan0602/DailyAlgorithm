//
// Created by ZD-Mac on 2021-01-18.
//

/*
 * 您需要在二叉树的每一行中找到最大的值。

示例：

输入:

          1
         / \
        3   2
       / \   \
      5   3   9

输出: [1, 3, 9]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
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
    vector<int> largestValues(TreeNode *root) {
        queue<TreeNode *> que;
        if (root != nullptr)
            que.push(root);
        vector<int> res;
        while (!que.empty()) {
            int size = que.size();
            int maxValue = INT_MIN;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                maxValue = node->val > maxValue ? node->val : maxValue;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            res.push_back(maxValue);
        }
        return res;
    }
};

