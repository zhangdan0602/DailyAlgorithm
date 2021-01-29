//
// Created by ZD-Mac on 2021-01-16.
//

/*
 * 给定一个有 N 个节点的二叉树，每个节点都有一个不同于其他节点且处于 {1, ..., N} 中的值。

通过交换节点的左子节点和右子节点，可以翻转该二叉树中的节点。

考虑从根节点开始的先序遍历报告的 N 值序列。将这一 N 值序列称为树的行程。

（回想一下，节点的先序遍历意味着我们报告当前节点的值，然后先序遍历左子节点，再先序遍历右子节点。）

我们的目标是翻转最少的树中节点，以便树的行程与给定的行程 voyage 相匹配。 

如果可以，则返回翻转的所有节点的值的列表。你可以按任何顺序返回答案。

如果不能，则返回列表 [-1]。

 

示例 1：



输入：root = [1,2], voyage = [2,1]
输出：[-1]
示例 2：



输入：root = [1,2,3], voyage = [1,3,2]
输出：[1]
示例 3：



输入：root = [1,2,3], voyage = [1,2,3]
输出：[]
 

提示：

1 <= N <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flip-binary-tree-to-match-preorder-traversal
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
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
        if (dfs(root, voyage)) {
            return res;
        }
        return {-1};
    }

private:
    int i = 0;
    vector<int> res;

    bool dfs(TreeNode *root, vector<int> &voyage) {
        if (!root) {
            return true;
        } else if (i >= voyage.size()) {
            return false;
        }
        if (root->val != voyage[i]) {
            return false;
        }
        i++;
        if (dfs(root->left, voyage) && dfs(root->right, voyage)) {
            return true;
        }
        if (dfs(root->right, voyage) && dfs(root->left, voyage)) {
            res.push_back(root->val);
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    vector<int> voyage = {2, 1};
    vector<int> res = solution.flipMatchVoyage(root, voyage);
    for (auto x : res) {
        cout << x << endl;
    }
    return 0;
}

