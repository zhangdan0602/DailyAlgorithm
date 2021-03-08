//
// Created by ZD-Mac on 2021/3/7.
//
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
