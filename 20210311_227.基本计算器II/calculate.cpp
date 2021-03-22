//
// Created by ZD-Mac on 2021/3/11.
//

/*
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

整数除法仅保留整数部分。



示例 1：

输入：s = "3+2*2"
输出：7
示例 2：

输入：s = " 3/2 "
输出：1
示例 3：

输入：s = " 3+5 / 2 "
输出：5


提示：

1 <= s.length <= 3 * 105
s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
s 表示一个 有效表达式
表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内
题目数据保证答案是一个 32-bit 整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char sign = '+';
        int num = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                num = 10 * num + (s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.length() - 1) {
                if (sign == '+') {
                    stk.push(num);
                } else if (sign == '-') {
                    stk.push(-num);
                } else if (sign == '*') {
                    int n = stk.top() * num;
                    stk.pop();
                    stk.push(n);
                } else if (sign == '/') {
                    int n = stk.top() / num;
                    stk.pop();
                    stk.push(n);
                }
                sign = s[i];
                num = 0;
            }
        }
        int res = 0;
        while (!stk.empty()) {
            int n = stk.top();
            res = res + n;
            stk.pop();
        }
        return res;
    }
};

int main() {

}
