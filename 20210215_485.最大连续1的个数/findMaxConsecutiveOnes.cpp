//
// Created by ZD-Mac on 2021/2/15.
//

/*
 * 给定一个二进制数组， 计算其中最大连续1的个数。

示例 1:

输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
注意：

输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-consecutive-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int maxLen = 0, curLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                curLen++;
            } else if (nums[i] == 0) {
                maxLen = max(maxLen, curLen);
                curLen = 0;
            }
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int res = solution.findMaxConsecutiveOnes(nums);
    cout << res << endl;
    return 0;
}