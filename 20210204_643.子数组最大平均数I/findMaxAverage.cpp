//
// Created by ZD-Mac on 2021-02-04.
//

#include <opencl-c-base.h>

/*
 * 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

 

示例：

输入：[1,12,-5,-6,50,3], k = 4
输出：12.75
解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 

提示：

1 <= k <= n <= 30,000。
所给数据范围 [-10,000，10,000]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-average-subarray-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        int maxSum = sum;
        for (int i = k; i < n; ++i) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = max(maxSum, sum);
        }
        return (double) maxSum / k;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    double res = solution.findMaxAverage(nums, 4);
    cout << res << endl;
    return 0;
}