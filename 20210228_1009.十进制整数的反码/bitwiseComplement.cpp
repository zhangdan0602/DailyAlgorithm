//
// Created by ZD-Mac on 2021/2/28.
//

/*
每个非负整数N都有其二进制表示。例如，5可以被表示为二进制"101"，11 可以用二进制"1011"表示，依此类推。注意，除N = 0外，任何二进制表示中都不含前导零。

二进制的反码表示是将每个1改为0且每个0变为1。例如，二进制数"101"的二进制反码为"010"。

给你一个十进制数N，请你返回其二进制表示的反码所对应的十进制整数。



示例 1：

输入：5
输出：2
解释：5 的二进制表示为 "101"，其二进制反码为 "010"，也就是十进制中的 2 。
示例 2：

输入：7
输出：0
解释：7 的二进制表示为 "111"，其二进制反码为 "000"，也就是十进制中的 0 。
示例 3：

输入：10
输出：5
解释：10 的二进制表示为 "1010"，其二进制反码为 "0101"，也就是十进制中的 5 。


提示：

0 <= N < 10^9
本题与 476：https://leetcode-cn.com/problems/number-complement/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/complement-of-base-10-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0)
            return 1;

        int temp1 = 1;
        int temp2 = N;

        while (temp2 > 0) {//不停用temp1对原整数进行异或运算，每次运算结束后将temp1朝左移动1位

            N ^= temp1;
            temp1 = temp1 << 1;
            temp2 = temp2 >> 1;
            cout << N << "\t" << temp1 << "\t" << temp2 << endl;
        }
        return N;
    }
};

int main() {
    Solution solution;
    int res = solution.bitwiseComplement(10);
    cout << res << endl;
    cout << (10 ^ 1) << endl;
    cout << (11 ^ 2) << endl;
    cout << (9 ^ 4) << endl;
    cout << (13 ^ 8) << endl;
    cout << (5 ^ 16) << endl;
    return 0;
}