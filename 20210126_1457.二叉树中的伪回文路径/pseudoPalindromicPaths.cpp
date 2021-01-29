//
// Created by ZD-Mac on 2021-01-26.
//

/*
 *给你一棵二叉树，每个节点的值为 1 到 9 。我们称二叉树中的一条路径是 「伪回文」的，当它满足：路径经过的所有节点值的排列中，存在一个回文序列。

请你返回从根到叶子节点的所有路径中 伪回文 路径的数目。

 

示例 1：



输入：root = [2,3,1,3,1,null,1]
输出：2
解释：上图为给定的二叉树。总共有 3 条从根到叶子的路径：红色路径 [2,3,3] ，绿色路径 [2,1,1] 和路径 [2,3,1] 。
     在这些路径中，只有红色和绿色的路径是伪回文路径，因为红色路径 [2,3,3] 存在回文排列 [3,2,3] ，绿色路径 [2,1,1] 存在回文排列 [1,2,1] 。
示例 2：



输入：root = [2,1,1,1,3,null,null,null,null,null,1]
输出：1
解释：上图为给定二叉树。总共有 3 条从根到叶子的路径：绿色路径 [2,1,1] ，路径 [2,1,3,1] 和路径 [2,1] 。
     这些路径中只有绿色路径是伪回文路径，因为 [2,1,1] 存在回文排列 [1,2,1] 。
示例 3：

输入：root = [9]
输出：1
 

提示：

给定二叉树的节点数目在 1 到 10^5 之间。
节点值在 1 到 9 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pseudo-palindromic-paths-in-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(0), left(nullptr), right(nullptr) {};
};

// 思路
// 1。得到路径
// 2。判断是否有伪回文
// 3。返回个数
class Solution {
public:
    int check(vector<int> &cnt) {
        int odd = 0;
        for (int i = 0; i <= 9; ++i) {
            if (cnt[i] & 1)
                odd++;
        }
        if (odd <= 1) {
            return 1;
        }
        return 0;
    }

    int dfs(TreeNode *root, vector<int> &cnt) {
        if (root == nullptr) {
            return 0;
        }
        cnt[root->val]++;
        if (root->left == nullptr && root->right == nullptr) {
            int res = check(cnt);
            cnt[root->val]--;
            return res;
        }
        int res = 0;
        if (root->left != nullptr) {
            res += dfs(root->left, cnt);
        }
        if (root->right != nullptr) {
            res += dfs(root->right, cnt);
        }
        cnt[root->val]--;
        return res;
    }

    int pseudoPalindromicPaths(TreeNode *root) {
        vector<int> cnt(10);
        return dfs(root, cnt);
    }
};
int main(){
    Solution solution;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    int res = solution.pseudoPalindromicPaths(root);
    cout << res << endl;
    return 0;
}

