//
// Created by ZD-Mac on 2020-12-02.
//
/*
 * 给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-k-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> s;
        string res = "";
        for (int i = 0; i < num.size(); ++i) {
            // 注意：不断地与邻居元素比较
            while (s.size() > 0 && k && s.back() > num[i]){
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
        }
        for (int j = k; j > 0; j--) {
            s.pop_back();
        }
        bool isleadzero = true;
        for (int l = 0; l < s.size(); ++l) {
            if (isleadzero && s[l] == '0'){
                continue;
            }
            isleadzero = false;
            res += s[l];
        }
        return res == "" ? "0" : res;
    }
};

int main(){
    Solution solution;
//    string res = solution.removeKdigits("1432219", 3);
//    string res = solution.removeKdigits("10200", 1);
    string res = solution.removeKdigits("1234567890", 9);
    cout << res << endl;
}
