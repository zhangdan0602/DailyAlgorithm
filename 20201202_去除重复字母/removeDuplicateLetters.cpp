//
// Created by ZD-Mac on 2020-12-02.
//

/*
 *3
 * 16. 去除重复字母
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters 相同



示例 1：

输入：s = "bcabc"
输出："abc"
示例 2：

输入：s = "cbacdcbc"
输出："acdb"


提示：

1 <= s.length <= 104
s 由小写英文字母组成

 */

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> char_count;
        vector<char> stk;
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            char_count[s[i]]++;
        }
        for (int j = 0; j < s.size(); ++j) {
            if (find(stk.begin(), stk.end(), s[j]) == stk.end()){
                while (stk.size() > 0 && stk.back() > s[j] && char_count[stk.back()] > 0){
                    stk.pop_back();
                }
                stk.push_back(s[j]);
            }
            char_count[s[j]]--;
        }
        for (int k = 0; k < stk.size(); ++k) {
            res += stk[k];
        }
        return res;
    }
};

int main(){
    Solution solution;
    string res = solution.removeDuplicateLetters("cbacdcbc");
    cout << res.size() << endl;
    cout << res << endl;
    return 0;
}