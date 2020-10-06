//
// Created by zd on 2020/10/6.
//
/*
 * 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

例如:
给定二叉树:[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof
 */
#include <cstdio>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> result;
        if(!root)
            return result;
        queue<TreeNode *> level;
        level.push(root);
        while (!level.empty()){
            int num = level.size();
            vector<int> levelNode;
            while (num > 0){
                TreeNode *temp = level.front();
                if (temp->left) level.push(temp->left);
                if (temp->right) level.push(temp->right);
                levelNode.push_back(temp->val);
                level.pop();
                num--;
            }
            result.push_back(levelNode);
        }
        return result;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solution;
    vector<vector<int>> res = solution.levelOrder(root);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << "\t" << endl;
        }
        cout << endl;
    }
};
