//
// Created by ZD-Mac on 2021/3/1.
//

/*
 * 给你一个数组 nums ，请你完成两类查询，其中一类查询要求更新数组下标对应的值，另一类查询要求返回数组中某个范围内元素的总和。

实现 NumArray 类：

NumArray(int[] nums) 用整数数组 nums 初始化对象
void update(int index, int val) 将 nums[index] 的值更新为 val
int sumRange(int left, int right) 返回子数组 nums[left, right] 的总和（即，nums[left] + nums[left + 1], ..., nums[right]）


示例：

输入：
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
输出：
[null, 9, null, 8]

解释：
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // 返回 9 ，sum([1,3,5]) = 9
numArray.update(1, 2);   // nums = [1,2,5]
numArray.sumRange(0, 2); // 返回 8 ，sum([1,2,5]) = 9


提示：

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
最多调用 3 * 104 次 update 和 sumRange 方法

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-mutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>

using namespace std;

class NumArray {
public:
    int n;
    vector<int> tree;
    vector<int> nums;
public:
    // 树状数组
    int lowbit(int x) {
        return x & (-x);
    }

    // 初始化 给每个节点加入树状数组中
    NumArray(vector<int> &nums) {
        this->n = nums.size();
        this->nums = nums;
        tree = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
            add(i, nums[i - 1]);
    }

    void add(int index, int val) {
        while (index <= n) {
            tree[index] += val;
            index += lowbit(index);
        }
    }

    // 记住 这里更新的是差值
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index + 1, delta);
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= lowbit(index);
        }
        return sum;
    }

    // 这里区间和是闭区间
    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */