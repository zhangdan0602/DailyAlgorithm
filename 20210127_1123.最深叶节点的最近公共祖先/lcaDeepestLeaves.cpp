//
// Created by ZD-Mac on 2021-01-27.
//
#include <iostream>

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
    int deepest(TreeNode *root) {
        if (!root) {
            return -1;
        }
        return 1 + max(deepest((root->left)), deepest(root->right));
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        if (!root)
            return nullptr;
        int left = deepest(root->left);
        int right = deepest(root->right);
        if (left == right) {
            return root;
        } else if (left > right) {
            return lcaDeepestLeaves(root->left);
        } else {
            return lcaDeepestLeaves(root->right);
        }
    }
};
