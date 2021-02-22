//
// Created by ZD-Mac on 2021-02-02.
//

/*
 * 给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。

返回仅包含 1 的最长（连续）子数组的长度。

 

示例 1：

输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：
[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
示例 2：

输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 

提示：

1 <= A.length <= 20000
0 <= K <= A.length
A[i] 为 0 或 1 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-consecutive-ones-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int n = A.size();
        int maxn = 0, left = 0, right = 0, res=0;
        while (right < n) {
            maxn += A[right];
            if (right - left + 1 > maxn + K) {
                maxn -= A[left++];
            } else{
                res++;
            }
            right++;
        }
        return res;
    }
};

int main() {
    Solution solution;
//    vector<int> A = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
//    int res = solution.longestOnes(A, 2);
    vector<int> A = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int res = solution.longestOnes(A, 3);
    cout << res << endl;
    return 0;
}

