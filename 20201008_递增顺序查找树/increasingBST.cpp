//
// Created by zd on 2020/10/8.
//
/*
 *
 * 给你一个树，请你 按中序遍历 重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。

示例 ：

输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
/        / \
1        7   9

输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
           \
            7
             \
              8
               \
                 9

提示：

给定树中的结点数介于 1 和100 之间。
每个结点都有一个从 0 到 1000 范围内的唯一整数值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-order-search-tree
 */
#include <cstdio>
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    TreeNode* head = new TreeNode(0), *pre = head;
    TreeNode* increasingBST(TreeNode* root){
        if (!root)
            return nullptr;
        increasingBST(root->left);
        pre->right = new TreeNode(root->val);
        pre = pre->right;
        increasingBST(root->right);
        return head->right;
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new  TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);
    root->left->left->left = new TreeNode(1);
    root->right->right->left = new TreeNode(7);
    Solution solution;
    TreeNode* res = solution.increasingBST(root);
    cout << res->val << endl;
    cout << res->right->val << endl;
}
