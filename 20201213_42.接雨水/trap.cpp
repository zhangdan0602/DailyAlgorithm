//
// Created by ZD-Mac on 2020-12-13.
//

/*
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 

提示：

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0){
            return 0;
        }
        /*
        int res = 0;
        for (int i = 1; i < height.size() - 1; ++i) {
            int left_max = 0, right_max = 0;
            for (int j = i; j >= 0; j--) {
                left_max = max(left_max, height[j]);
            }
            for (int k = i; k < height.size(); ++k) {
                right_max = max(right_max, height[k]);
            }
            res += min(left_max, right_max) - height[i];
        }
        return res;
        */
        int res = 0;
        vector<int> left(height.size()), right(height.size());
        left[0] = height[0];
        right[height.size() - 1] = height[height.size() - 1];
        for (int i = 1; i < height.size(); ++i) {
            left[i] = max(height[i], left[i - 1]);
        }
        for (int j = height.size() - 2; j >= 0; j--) {
            right[j] = max(height[j], right[j + 1]);
        }
        for (int k = 1; k < height.size() - 1; ++k) {
            res += min(left[k], right[k]) - height[k];
        }
        return res;
    }
};
int main(){
    Solution solution;
    vector<int> vec = {4,2,0,3,2,5};
    int res = solution.trap(vec);
    cout << res << endl;
    return 0;
}