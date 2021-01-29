//
// Created by ZD-Mac on 2021-01-18.
//

/*
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int n;
    vector<string> temp;
    vector<vector<string>> res;

    bool isPalind(string s) {
        int len = s.length();
        for (int i = 0; i < len / 2; ++i) {
            if (s[i] != s[len - 1 - i])
                return false;
        }
        return true;
    }

    void backtrack(string s, int i) {
        if (i == n) {
            res.push_back(temp);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (isPalind(s.substr(i, j - i + 1))) {
                temp.push_back(s.substr(i, j - i + 1));
                backtrack(s, j + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();
        if (n == 0) {
            return res;
        }
        backtrack(s, 0);
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> res = solution.partition("aab");
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << endl;
        }
    }
    return 0;
}