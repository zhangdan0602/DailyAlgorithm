//
// Created by ZD-Mac on 2021/2/28.
//

/*
 * 给定一个大小为n的整数数组，找出其中所有出现超过⌊ n/3 ⌋次的元素。

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。



示例1：

输入：[3,2,3]
输出：[3]
示例 2：

输入：nums = [1]
输出：[1]
示例 3：

输入：[1,1,1,3,3,2,2,2]
输出：[1,2]


提示：

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> res;
        int n = nums.size() / 3;
        map<int, int> m;
        for (int num:nums) {
            if (m.count(num) == 0) {
                m[num] = 1;
            } else {
                int cnt = m[num];
                m[num] = cnt + 1;
            }
        }
        for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second > n) {
                res.push_back(iter->first);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
//    vector<int> nums = {3, 2, 3};
//    vector<int> nums = {1};
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> res = solution.majorityElement(nums);
    for (int r:res) {
        cout << r << endl;
    }
    return 0;
}