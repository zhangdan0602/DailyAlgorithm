//
// Created by ZD-Mac on 2020-12-15.
//

/*
 * 给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:

输入: N = 10
输出: 9
示例 2:

输入: N = 1234
输出: 1234
示例 3:

输入: N = 332
输出: 299
说明: N 是在 [0, 10^9] 范围内的一个整数。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotone-increasing-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string digit = to_string(N);
        int size = digit.size();
        int index = 0;
        while (index < size - 1 && digit[index] - '0' <= digit[index + 1] - '0'){
            index++;
        }
        if (index == size - 1){
            return N;
        }
        digit[index] = digit[index] - 1;
        for (int i = index + 1; i < size; ++i) {
            digit[i] = '9';
        }
        for (int j = index; j > 0 ; --j) {
            if(digit[j] - '0' < digit[j - 1] - '0'){
                digit[j] = '9';
                digit[j - 1] = digit[j - 1] - 1;
            } else{
                break;
            }
        }
        return stoi(digit);
    }
};
int main(){
    Solution solution;
    int res = solution.monotoneIncreasingDigits(1429);
    cout << res << endl;
    return 0;
}