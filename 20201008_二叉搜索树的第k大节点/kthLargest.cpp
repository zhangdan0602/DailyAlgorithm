//
// Created by zd on 2020/10/8.
//
/*
 *给定一棵二叉搜索树，请找出其中第k大的节点。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
  2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof
 */
#include <cstdio>
#include <iostream>
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
    vector<int> order;
    void recursive(TreeNode* node){
        if (!node)
            return;
        if (node->left)
            recursive(node->left);
        order.push_back(node->val);
        if (node->right)
            recursive(node->right);
    }
    int kthLargest(TreeNode* root, int k){
        if (!root)
            return 0;
        recursive(root);
        return order[order.size() - k];
    }
};

int main(){
    Solution solution;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int kVal = solution.kthLargest(root, 1);
    cout << kVal << endl;
}