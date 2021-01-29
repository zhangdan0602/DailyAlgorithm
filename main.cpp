#include <iostream>
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(0), left(nullptr), right(nullptr){};
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
