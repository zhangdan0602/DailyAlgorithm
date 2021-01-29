//
// Created by ZD-Mac on 2021-01-17.
//

/*
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void construct_paths(TreeNode *root, string path, vector<string> &paths) {
        if (root != nullptr) {
            path += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr) {
                paths.push_back(path);
            } else {
                path += "->";
                construct_paths(root->left, path, paths);
                construct_paths(root->right, path, paths);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> paths;
        construct_paths(root, "", paths);
        return paths;
    }
};

int main() {
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<string> res = solution.binaryTreePaths(root);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;
}
