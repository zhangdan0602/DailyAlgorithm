//
// Created by ZD-Mac on 2021-01-18.
//

/*
 * 根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <unordered_map>

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
    int post_index;
    unordered_map<int, int> index_map;

public:
    TreeNode *helper(int in_left, int in_right, vector<int> &inorder, vector<int> &postorder) {
        if (in_left > in_right)
            return nullptr;
        int root_val = postorder[post_index];
        TreeNode *root = new TreeNode(root_val);
        int index = index_map[root_val];
        post_index--;
        root->right = helper(index + 1, in_right, inorder, postorder);
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        post_index = postorder.size() - 1;
        int index = 0;
        for (auto &val : inorder) {
            index_map[val] = index++;
        }
        return helper(0, inorder.size() - 1, inorder, postorder);
    }
};