//
// Created by ZD-Mac on 2021-01-16.
//

/*
 * 给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其余元素是 emails 表示该账户的邮箱地址。

现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。

合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。账户本身可以以任意顺序返回。

 

示例 1：

输入：
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John",
 "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
输出：
[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"],
 ["Mary", "mary@mail.com"]]
解释：
第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。
第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。
 

提示：

accounts的长度将在[1，1000]的范围内。
accounts[i]的长度将在[1，10]的范围内。
accounts[i][j]的长度将在[1，30]的范围内。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/accounts-merge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<int> f;
    unordered_map<string, int> father;
    unordered_set<string> isAppeared;

public:
    int find(int x) {
        return x == f[x] ? x : find(f[x]);
    }

    void merge(int x, int y) {
        int xF = find(x);
        int yF = find(y);
        if (xF != yF)
            f[yF] = xF;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        vector<vector<string>> res;
        f = vector<int>(accounts.size());
        for (int i = 0; i < f.size(); ++i) {
            f[i] = i;
        }
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (!isAppeared.count(accounts[i][j])) {
                    isAppeared.insert(accounts[i][j]);
                    father[accounts[i][j]] = i;
                } else {
                    merge(father[accounts[i][j]], i);
                }
            }
        }
        unordered_map<int, set<string>> accMail;
        for (int i = 0; i < accounts.size(); ++i) {
            int t = find(i);
            int len = accounts[i].size();
            for (int j = 1; j < len; ++j) {
                accMail[t].insert(accounts[i][j]);
            }
        }
        for (auto acc: accMail) {
            vector<string> ans;
            ans.push_back(accounts[acc.first][0]);
            for (auto mail:acc.second) {
                ans.push_back(mail);
            }
            res.push_back(ans);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"},
                                       {"John", "johnnybravo@mail.com"},
                                       {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                       {"Mary", "mary@mail.com"}};
    vector<vector<string>> res = solution.accountsMerge(accounts);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << endl;
        }
    }
    return 0;
}