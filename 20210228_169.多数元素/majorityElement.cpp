//
// Created by ZD-Mac on 2021/2/28.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int maxCount = 0, maxNum = nums[0];
        int n = nums.size() / 2;
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
                if (maxCount < iter->second) {
                    maxCount = iter->second;
                    maxNum = iter->first;
                }
            }
        }
        return maxNum;
    }
};

int main() {
    Solution solution;
//    vector<int> nums = {3, 2, 3};
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
//    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    int num = solution.majorityElement(nums);
    cout << num << endl;
    return 0;
}