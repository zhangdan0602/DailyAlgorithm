//
// Created by ZD-Mac on 2020-12-16.
//

/*
 *
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例 4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。

 */
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> str2ch;
        unordered_map<char, string> ch2str;
        int m = s.size();
        int i = 0;
        for (auto ch : pattern){
            if(i > m){ return false;}
            int j = i;
            while (j < m && s[j] != ' ')
                j++;
            const string &tmp = s.substr(i, j - i);
            if (str2ch.count(tmp) && str2ch[tmp] != ch){
                return false;
            }
            if(ch2str.count(ch) && ch2str[ch] != tmp)
                return false;
            str2ch[tmp] = ch;
            ch2str[ch] = tmp;
            i = j + 1;
        }
        return i >= m;
    }
};
int main(){
    Solution solution;
    bool res = solution.wordPattern("abba", "dog cat cat dog");
    cout << res << endl;
    return 0;
}