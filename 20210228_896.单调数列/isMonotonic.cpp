//
// Created by ZD-Mac on 2021/2/28.
//

/*
 * 如果数组是单调递增或单调递减的，那么它是单调的。

如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。

当给定的数组 A是单调数组时返回 true，否则返回 false。



示例 1：

输入：[1,2,2,3]
输出：true
示例 2：

输入：[6,5,4,4]
输出：true
示例 3：

输入：[1,3,2]
输出：false
示例 4：

输入：[1,2,4,5]
输出：true
示例5：

输入：[1,1,1]
输出：true


提示：

1 <= A.length <= 50000
-100000 <= A[i] <= 100000
通过次数26,593提交次数47,634

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotonic-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int> &A) {
        return is_sorted(A.begin(), A.end()) || is_sorted(A.rbegin(), A.rend());

//        if (A.size() == 0 || A.size() == 1 || A.size() == 2) {
//            return true;
//        }
//        int cnt = 0;
//        for (int i = 1; i < A.size(); ++i) {
//            if (A[i] == A[i - 1]) {
//                cnt++;
//            }
//        }
//        if (cnt == A.size() - 1) {
//            return true;
//        }
//        vector<int> newA;
//        newA.push_back(A[0]);
//        for (int i = 1; i < A.size(); ++i) {
//            if (A[i] == A[i - 1]) {
//                continue;
//            } else {
//                newA.push_back(A[i]);
//            }
//        }
//
//        if (newA[0] <= newA[1]) {
//            for (int i = 1; i < newA.size(); ++i) {
//                if (newA[i] - newA[i - 1] < 0) {
//                    return false;
//                }
//            }
//        } else if (newA[0] >= newA[1]) {
//            for (int i = 1; i < newA.size(); ++i) {
//                if (newA[i] - newA[i - 1] > 0) {
//                    return false;
//                }
//            }
//        }
//        return true;
    }
};

int main() {
    Solution solution;

//    vector<int> A = {1, 1, 1};
//    vector<int> A = {1, 2, 2, 3};
//    vector<int> A = {6,5,4,4};
    vector<int> A = {1, 3, 2};
//    vector<int> A = {1,2,4,5};
//    vector<int> A = {1, 1, 0};
//    vector<int> A = {5, 5, 5, 5, 2, 2, 2, 1, 1, 1, 0};
    bool res = solution.isMonotonic(A);
    cout << res << endl;
    return 0;
}