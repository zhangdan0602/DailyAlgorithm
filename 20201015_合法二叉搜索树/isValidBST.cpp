//
// Created by zd18 on 2020/10/14.
//
/*
 * 实现一个函数，检查一棵二叉树是否为二叉搜索树。

示例1:
输入:
    2
   / \
  1   3
输出: true
示例2:
输入:
    5
   / \
  1   4
    / \
   3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
    根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/legal-binary-search-tree-lcci
*/

#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};
class Solution{
public:
    vector<int> res;
    void midOrder(TreeNode *root){
        if (root == NULL)
            return;
        midOrder(root->left);
        res.push_back(root->val);
        midOrder(root->right);
    }
    bool isValidBST(TreeNode* root){
        if (!root)
            return true;
        midOrder(root);
        if (res.size() == 1)
            return true;
        for (int i = 0; i < res.size() - 1; ++i) {
            if (res[i] >= res[i + 1])
                return false;
        }
        return true;
    }
};

int main(){
    Solution solution;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    bool result = solution.isValidBST(root);
    cout << result << endl;
}