//
// Created by ZD-Mac on 2020-12-02.
//
/*
 * 给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。
 * 现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。

求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。

说明: 请尽可能地优化你算法的时间和空间复杂度。

示例 1:

输入:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
输出:
[9, 8, 6, 5, 3]
示例 2:

输入:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
输出:
[6, 7, 6, 0, 4]
示例 3:

输入:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
输出:
[9, 8, 9]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/create-maximum-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        int start = fmax(0, k - (int)nums2.size()), end = fmin(k, (int)nums1.size());
        for (int i = start; i <= end; ++i) {
            vector<int> seqNum1(maxSequenceNumber(nums1, i));
            vector<int> seqNum2(maxSequenceNumber(nums2, k - i));
            vector<int> mergeSeq(merge(seqNum1, seqNum2));
            if (compare(mergeSeq, 0, res, 0) > 0){
                res.swap(mergeSeq);
            }
        }
        return res;
    }

    vector<int> maxSequenceNumber(vector<int>& nums, int n){
        vector<int> res;
        int k = nums.size() - n;
        for (int i = 0; i < nums.size(); ++i) {
            while (res.size() > 0 && res.back() < nums[i] && k){
                res.pop_back();
                k--;
            }
            res.push_back(nums[i]);
        }
        for (; k > 0 ; k--) {
            res.pop_back();
        }
        cout << "res:" << res.size() << endl;
        for (int m = 0; m < res.size(); ++m) {
            cout << res[m] << "\t";
        }
        return res;
    }

    vector<int> merge(vector<int>& subsequence1, vector<int>& subsequence2){
        int x = subsequence1.size(), y = subsequence2.size();
        if (x == 0) {
            return subsequence2;
        }
        if (y == 0) {
            return subsequence1;
        }
        int mergeLength = x + y;
        vector<int> merged(mergeLength);
        int index1 = 0, index2 = 0;
        for (int i = 0; i < mergeLength; i++) {
            if (compare(subsequence1, index1, subsequence2, index2) > 0) {
                merged[i] = subsequence1[index1++];
            } else {
                merged[i] = subsequence2[index2++];
            }
        }
        return merged;
        /*
         int i = 0, j = 0, k =0;
        vector<int> res(nums1.size() + nums2.size(), 0);
        while (i < nums1.size() && j < nums2.size()){
            if (nums1[i] >= nums2[j]){
                res[k++] = nums1[i++];
            } else{
                res[k++] = nums2[j++];
            }
        }
        while (i < nums1.size()){
            res[k++] = nums1[i++];
        }
        while (j < nums2.size()){
            res[k++] = nums2[j++];
        }
        return res;
         */
    }
    int compare(vector<int>& nums1, int i, vector<int>& nums2, int j){
        while (i < nums1.size() && j < nums2.size()){
            int delta = nums1[i] - nums2[j];
            if (delta != 0){
                return delta;
            }
            i++;
            j++;
        }
        return (nums1.size() - i) - (nums2.size() - j);
    }
};

int main(){
    Solution solution;
//    vector<int> num1 = {3, 4, 6, 5};
//    vector<int> num2 = {9, 1, 2, 5, 8, 3};
//    vector<int> num1 = {6, 7};
//    vector<int> num2 = {6, 0, 4};
    vector<int> num1 = {2,5,6,4,4,0};
    vector<int> num2 = {7,3,8,0,6,5,7,6,2};


    vector<int> res = solution.maxNumber(num1, num2, 15);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << "\t";
    }
    return 0;
}