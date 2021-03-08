//
// Created by ZD-Mac on 2021/2/27.
//

/*
 * 找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。

示例 1:

输入:
s = "aaabb", k = 3

输出:
3

最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2:

输入:
s = "ababbc", k = 2

输出:
5

最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
//    int longestSubstring(string s, int k) {
//        int cnt = 0;
//        for (int i = 1; i < s.length(); ++i) {
//            if (s[i] == s[i - 1]) {
//                cnt++;
//            }
//        }
//        cout << cnt << endl;
//        if (cnt + 1 == s.length() && cnt >= k)
//            return s.length();
//        int left = 0, right = s.length() - 1, res = 0;
//        for (left = 0; left <= right + 1 - k; left++) {
//            while (right - left + 1 >= k) {
//                string sub = s.substr(left, (right - left + 1));
//                cout << sub << endl;
//                map<char, int> mapsub;
//                for (auto &ch:sub) {
//                    if (mapsub.count(ch) == 0) {
//                        mapsub[ch] = 1;
//                    } else {
//                        int num = mapsub[ch];
//                        mapsub[ch] = num + 1;
//                    }
//                }
//                int n = mapsub.size(), cnt = 0;
//                for (map<char, int>::iterator iter = mapsub.begin(); iter != mapsub.end(); iter++) {
//                    if (iter->second >= k) {
//                        cnt++;
//                    }
//                }
//                if (cnt == n) {
//                    cout << sub << endl;
//                    int len = sub.length();
//                    if (res < len) {
//                        res = len;
//                    }
//                }
//                right--;
//            }
//            right = s.length() - 1;
//        }
//        return res;
//    }
    int dfs(const string &s, int l, int r, int k) {
        vector<int> cnt(26, 0);
        for (int i = l; i <= r; i++) {
            cnt[s[i] - 'a']++;
        }

        char split = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split = i + 'a';
                break;
            }
        }
        if (split == 0) {
            return r - l + 1;
        }

        int i = l;
        int ret = 0;
        while (i <= r) {
            while (i <= r && s[i] == split) {
                i++;
            }
            if (i > r) {
                break;
            }
            int start = i;
            while (i <= r && s[i] != split) {
                i++;
            }

            int length = dfs(s, start, i - 1, k);
            ret = max(ret, length);
        }
        return ret;
    }

    int longestSubstring(string s, int k) {
        int n = s.length();
        return dfs(s, 0, n - 1, k);
    }
};

int main() {
    Solution solution;
//    int res = solution.longestSubstring("aaabb", 3);
//    int res = solution.longestSubstring("ababbc", 2);
    int res = solution.longestSubstring("aaaaaaa", 3);
    cout << res << endl;
    return 0;
}