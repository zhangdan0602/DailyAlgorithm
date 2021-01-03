//
// Created by ZD-Mac on 2020-12-22.
//


/*
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        queue<TreeNode *> level;
        level.push(root);
        bool isOrderLeft = true;
        while (!level.empty()){
            deque<int> levelList;
            int num = level.size();
//            vector<int> levelNode;
            while (num > 0){
                TreeNode *temp = level.front();
                if (isOrderLeft) levelList.push_back(temp->val);
                else levelList.push_front(temp->val);
                if (temp->left) level.push(temp->left);
                if (temp->right) level.push(temp->right);
//                levelNode.push_back(temp->val);
                level.pop();
                num--;
            }
            result.push_back(vector<int>{levelList.begin(), levelList.end()});
            isOrderLeft = !isOrderLeft;
//            result.push_back(levelNode);

        }
        return result;
    }
};