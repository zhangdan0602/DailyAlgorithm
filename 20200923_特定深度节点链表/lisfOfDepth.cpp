//
// Created by zd on 2020/9/23.
//

/*
 * Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth
 * (e.g., if you have a tree with depth D, you'll have D linked lists). Return a array containing all the linked lists.

Example:

Input: [1,2,3,4,5,null,7,8]

        1
       /  \
      2    3
     / \    \
    4   5    7
   /
  8

Output: [[1],[2,3],[4,5,7],[8]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/list-of-depth-lcci
 */

#include <cstdlib>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    vector<ListNode*> listOfDepth(TreeNode* tree){
        vector<ListNode *> result;
        if (!tree)
            return result;
        queue<TreeNode *> level;
        level.push(tree);
        while (!level.empty()){
            int num = level.size();
            ListNode *leftNode = nullptr;
            while (num > 0){
                TreeNode *temp = level.front();
                if (!leftNode){
                    cout << "first element:" << endl;
                    leftNode = new ListNode(temp -> val);
                    cout << leftNode->val << endl;
                    result.push_back(leftNode);
                } else{
                    cout << "not first element:" << endl;
                    leftNode -> next = new ListNode(temp -> val);
                    leftNode = leftNode -> next;
                    cout << leftNode->val << endl;

                }
                if (temp -> left)
                    level.push(temp -> left);
                if(temp -> right)
                    level.push(temp -> right);
                level.pop();
                num--;
            }
        }
        return result;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> right -> left = new TreeNode(6);
    vector<ListNode *> res;
    Solution solution;
    res = solution.listOfDepth(root);
}
/*
 * 层次遍历
 * 每一层结果为一个链表
 * 每一链表同时存入结果数组中*/

